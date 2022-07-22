#pragma once
#include <string>
#include <unistd.h>

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

}

// Global overloads:
bool    operator>(const timespec &f, const timespec &s)
{
    return (f.tv_sec + f.tv_nsec / 1000000000)
            > (s.tv_sec + s.tv_nsec / 1000000000);
}
