#include <iostream>

#include "server.h"

int main(int ac, char **av)
{
    (void)av;
    if (ac < 2)
    {
        std::cerr << "Using default configuration" << std::endl;
    }
    Server webserv;
    webserv.Run();
}
