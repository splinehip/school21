#include <iostream>
#include <csignal>

#include "logger/Log.h"
#include "Server.hpp"

std::string sigstr(int signum)
{
    switch (signum)
    {
    case SIGINT:
        return ("SIGINT");
    case SIGABRT:
        return ("SIGABRT");
    case SIGTERM:
        return ("SIGTERM");
    default:
        return ("Unkonwn signal");
    }
}

void signal_handler(int signum)
{
    logger::Log &log = logger::Log::getInst();

    std::cout << std::endl;
    log(logger::INFO, "Signal received: %i (%s), do exit.", signum,
        sigstr(signum).c_str());
    exit(signum);
}

int main(int argc, char **argv)
{
    signal(SIGINT, signal_handler);
    signal(SIGABRT, signal_handler);
    signal(SIGTERM, signal_handler);

    logger::Log &log = logger::Log::getInst(argv[0]);
    log.setLevel("DEBUG");

    std::string port = "6667";
    std::string pass = "";

    if (argc != 1 && argc != 3)
    {
        log(logger::ERROR,
            "Invalid arguments numbers. Use: %s <port> <password>", argv[0]);
        exit(EXIT_FAILURE);
    }
    else if (argc == 1)
    {
        log(logger::INFO, "default port: 6667 and password: empty will use.");
    }
    else
    {
        port = argv[1];
        pass = argv[2];
    }
    srv::Server server(port, pass);
    server.run();
    return (0);
}
