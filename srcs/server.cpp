#include "server.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

#include <iostream>

#define POLL_TIMEOUT -1

Server::Server()
{
    Init();
    Listen();
    AddToPdfs(m_ListeningSocket, {POLLIN});
}

void Server::Run()
{
    while(true)
    {
        int poll_cnt = poll(m_SocketsPdfs.data(), m_SocketsPdfs.size(), POLL_TIMEOUT);

        if (poll_cnt == -1)
        {
            perror("poll");
            exit(1);
        }

        for (size_t i = 0, visited = 0; i < m_SocketsPdfs.size(); ++i)
        {
            if (m_SocketsPdfs[i].revents == 0)
            {
                continue;
            }
            if (m_SocketsPdfs[i].revents & POLLIN)
            {
                if (m_SocketsPdfs[i].fd == m_ListeningSocket)
                {
                    sockaddr_storage connecting_address = {};
                    socklen_t storage_size = sizeof(connecting_address);
                    int connected_socket = accept(m_ListeningSocket, reinterpret_cast<sockaddr*>(&connecting_address), &storage_size);
                    if (connected_socket == -1)
                    {
                        perror("accept");
                    }
                    else
                    {
                        AddToPdfs(connected_socket, {POLLIN, POLLOUT});

                        char remote_ip[INET6_ADDRSTRLEN];
                        std::cout
                            << "New connection from "
                            << inet_ntop(connecting_address.ss_family, GetInputAddr(reinterpret_cast<sockaddr*>(&connecting_address)), remote_ip, sizeof(remote_ip))
                            << " with socket "
                            << connected_socket
                            << std::endl;
                    }
                }
                else
                {
                    char rec_buf[512];
                    int bytes_cnt = recv(m_SocketsPdfs[i].fd, rec_buf, sizeof(rec_buf), 0);
                    if (bytes_cnt <=  0)
                    {
                        if (bytes_cnt == 0)
                        {
                            std::cout << "Socket " << m_SocketsPdfs[i].fd << " closed connection" << std::endl;
                        }
                        else if (bytes_cnt == -1)
                        {
                            perror("recv");
                        }
                        close(m_SocketsPdfs[i].fd);
                        DelFromPdfs(i);
                    }
                }
            }
            else if (m_SocketsPdfs[i].revents & POLLOUT)
            {
                if (send(m_SocketsPdfs[i].fd, "Hello", 5, 0) == -1)
                {
                    perror("send");
                }
            }
            ++visited;
            if (static_cast<int>(visited) == poll_cnt)
            {
                break;
            }
        }
    }
}

void Server::Init()
{
    addrinfo hints = {};
    hints.ai_family = AF_UNSPEC; /// auto determining IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE; /// use my IP address as host. Write INADDR_ANY to IP address

    addrinfo *results;
    int rv;
    if ((rv = getaddrinfo(NULL, DEF_PORT, &hints, &results)) != 0)
    {
        std::cerr << "Getaddrinfo error: " << gai_strerror(rv) << std::endl;
        exit(1);
    }

    addrinfo *curr;
    for (curr = results; curr != NULL; curr = curr->ai_next)
    {
        if ((m_ListeningSocket = socket(curr->ai_family, curr->ai_socktype, curr->ai_protocol)) == -1)
        {
            perror("socket");
            continue;
        }

        int yes = 1; /// may be need char for Sun and Win
        if (setsockopt(m_ListeningSocket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1) /// skip "Address already in use" when old socket wasn't closed
        {
            perror("setsockopt");
            exit(1);
        }

        if (bind(m_ListeningSocket, curr->ai_addr, curr->ai_addrlen) == -1)
        {
            perror("socket");
            continue;
        }
        break;
    }

    if (curr == NULL)
    {
        std::cerr << "Error getting listening socket" << std::endl;
        exit(1);
    }

    freeaddrinfo(results);
}

void Server::Listen()
{
    if (listen(m_ListeningSocket, LISTEN_BACKLOG) == -1)
    {
        perror("listen");
        exit(1);
    }
}

void Server::AddToPdfs(int socket, std::vector<short> events)
{
    pollfd inserting = {};
    inserting.fd = socket;

    for (size_t i = 0; i < events.size(); ++i)
    {
        inserting.events |= events[i];
    }

    m_SocketsPdfs.push_back(inserting);
}

void Server::DelFromPdfs(size_t deleted_idx)
{
    m_SocketsPdfs.erase(m_SocketsPdfs.begin() + deleted_idx);
}

void *Server::GetInputAddr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET)
    {
        return &(reinterpret_cast<sockaddr_in*>(sa)->sin_addr);
    }
    return &(reinterpret_cast<sockaddr_in6*>(sa)->sin6_addr);
}
