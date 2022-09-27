#pragma once
#include <string>
#include <fcntl.h>
#include <unistd.h>

// Global overloads:
bool    operator>(const timespec &f, const timespec &s)
{
    return (f.tv_sec + f.tv_nsec / 1000000000)
            > (s.tv_sec + s.tv_nsec / 1000000000);
}

bool    operator<(const struct in_addr &f, const struct in_addr &s)
{
    return (ntohl(f.s_addr) < ntohl(s.s_addr));
}

bool    operator==(const struct in_addr &f, const struct in_addr &s)
{
    return (ntohl(f.s_addr) == ntohl(s.s_addr));
}

namespace utl
{
int     readFileToString(int fd, std::string &str)
{
    char buf[4096];
    str.clear();
    int res = read(fd, &buf, 4096);
    while (res > 0)
    {
        str += std::string(buf);
        res = read(fd, &buf, 4096);
    }
    return res;
}


// Sockets
int sockSetNonBlock(int &fd)
{
    int flags;

    #if defined (O_NONBLOCK)
        if (-1 == (flags = fcntl(fd, F_GETFL, 0)))
            flags = 0;
        return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
    #else
        flags = 1;
        return ioctl(fd, FIOBIO, &flags);
    #endif
}

int sockSetReuseAddr(int &fd)
{
    logger::Log &log = logger::Log::getInst();
    int optval = 1;
    if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &optval,
                    sizeof(optval)))
    {
        log(logger::ERROR, "sockSetReuseAddr: set opt SO_REUSEADDR failed: %s",
            strerror(errno));
        return -1;
    }
    return 0;
}

struct lessAddr
{
    bool
    operator()(const struct sockaddr_in &f, const struct sockaddr_in &s) const
    {
        if (f.sin_addr == s.sin_addr)
        {
            if (ntohs(f.sin_port) < ntohs(s.sin_port))
                return true;
            return false;
        }
        return f.sin_addr < s.sin_addr;
    }
};

}
