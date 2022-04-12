#include <iostream>

#include "Server.h"
#include "Logger/Logger.hpp"

int main(int ac, char **av)
{
    Server webserv;
    (void)av;
    if (ac < 2)
    {
        webserv.log.write(INFO,
            "Config file not set. Using default configuration");
    }
    webserv.Run();
}
