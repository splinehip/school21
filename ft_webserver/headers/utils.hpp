#pragma once
#include <string>
#include <unistd.h>

namespace utl
{
static const int POST = 0x01;
static const int GET = 0x02;
static const int PUT = 0x04;
static const int DELETE = 0x08;

unsigned short  httpMethod(const std::string &str)
{
    if (str == "POST")
        return POST;
    if (str == "GET")
        return GET;
    if (str == "PUT")
        return PUT;
    if (str == "DELETE")
        return DELETE;
    return 0;
}

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

int setNonBlock(int &fd)
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

}

// Global overloads:
bool    operator>(const timespec &f, const timespec &s)
{
    return (f.tv_sec + f.tv_nsec / 1000000000)
            > (s.tv_sec + s.tv_nsec / 1000000000);
}
