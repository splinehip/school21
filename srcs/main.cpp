#include <iostream>

//#include "Server.h"
#include "Logger/Logger.hpp"

int main(int ac, char **av)
{
    Logger  log("DEBUG", "webserv.log");
    (void)av;
    if (ac < 2)
    {
        log.write(INFO, "Config file not set. Using default configuration");
    }
    /* Server webserv;
    webserv.Run();*/
}
