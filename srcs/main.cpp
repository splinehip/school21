#include <iostream>
#include <csignal>

#include "logger/Log.h"
#include "Config.hpp"

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

    if (argc > 2)
    {
        log(logger::ERROR,
            "Invalid arguments numbers. Use: %s path_to_config_file", argv[0]);
        exit(EXIT_FAILURE);
    }
    else if (argc < 2)
    {
        log(logger::INFO,
            "No path_to_config_file, default config will use.");
        exit(EXIT_FAILURE);
    }

    return (0);
}
