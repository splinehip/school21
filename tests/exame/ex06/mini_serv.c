#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void    fatal(void)
{
    write(2, "Fatal error\n", strlen("Fatal error\n"));
    exit(1);
}

typedef struct cl
{
    int id;
    char *msg;
} cli_t;

int ls = 0;
int id = 0;
int maxfd = 0;
fd_set rd, wr, cur;
struct sockaddr_in addr;
cli_t cls[SOMAXCONN];

void    add(void)
{
    char msg[128];
    int fd = accept(ls, 0, 0);
    if (fd < 0)
        return;
    FD_SET(fd, &cur);
    cls[fd].id = id++;
    sprintf(msg, "server: client %d just arrived\n", cls[fd].id);
    for (int i = 0; i <= maxfd; i++)
    {
        if (i != ls && FD_ISSET(i, &wr))
            send(i, msg, strlen(msg), 0);
    }
    if (fd > maxfd)
        maxfd = fd;
}

void    rm(int fd)
{
    char msg[128];
    sprintf(msg, "server: client %d just left\n", cls[fd].id);
    free(cls[fd].msg);
    memset(&cls[fd], 0, sizeof(cli_t));
    FD_CLR(fd, &cur);
    for (int i = 0; i <= maxfd; i++)
    {
        if (i != ls && i != fd && FD_ISSET(i, &wr))
            send(i, msg, strlen(msg), 0);
    }
    close(fd);
    fd = maxfd;
    maxfd = ls;
    for (int i = 0; i <= fd; i++)
    {
        if (cls[i].id)
            maxfd = i;
    }
    if (fd == ls && FD_ISSET(4, &cur))
        maxfd = 4;
    else
        maxfd = fd;
}

void    send_msg(int fd)
{
    char hd[128];
    char *msg = 0;
    sprintf(hd, "client %d: ", cls[fd].id);
    while (extract_message(&cls[fd].msg, &msg) > 0)
    {
        for (int i = 0; i < maxfd; i++)
        {
            if (i != ls && i != fd && FD_ISSET(i, &wr))
            {
                send(i, hd, strlen(hd), 0);
                send(i, msg, strlen(msg), 0);
            }
        }
        free(msg);
        msg = 0;
    }
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
        exit(1);
    }
    char buf[4096];
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(2130706433);
    addr.sin_port = htons(atoi(av[1]));
    memset(cls, 0, sizeof(cli_t) * SOMAXCONN);
    ls = socket(AF_INET, SOCK_STREAM, 0);
    if (ls < 0)
        fatal();
    maxfd = ls;
    FD_ZERO(&cur);
    FD_SET(ls, &cur);
    if (bind(ls, (struct sockaddr *)(&addr), sizeof(addr)))
        fatal();
    if (listen(ls, SOMAXCONN))
        fatal();
    while (1)
    {
        rd = wr = cur;
        if (select(maxfd + 1, &rd, &wr, 0, 0) < 0)
            continue;
        if (FD_ISSET(ls, &rd))
            add();
        for (int i = 0; i <=maxfd; i++)
        {
            if (i != ls && FD_ISSET(i, &rd))
            {
                memset(buf, 0, 4096);
                int ret = recv(i, buf, 4095, 0);
                if (ret > 0)
                {
                    cls[i].msg = str_join(cls[i].msg, buf);
                    send_msg(i);
                }
                else
                {
                    rm(i);
                    break;
                }
            }
        }
    }
}
