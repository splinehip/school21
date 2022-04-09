#include <iostream>

#include "Logger.hpp"
//#include "server.h"
#include "unistd.h"

int main(int ac, char **av)
{
    Logger  log("Debug", "webserv.log");

    (void)av;
    if (ac < 2)
    {
       log.write(Debug, "Using default configuration");
    }
    /* Server webserv;
    webserv.Run(); */
    sleep(3);
}
