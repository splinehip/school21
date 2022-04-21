#include <iostream>
#include <csignal>

#include "Server.h"
#include "logger/Log.h"

static std::string sigstr(int signum)
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

static void signal_handler(int signum)
{
    logger::Log &log = logger::Log::getInst();

    std::cout << std::endl;
    log.write(logger::INFO, "Signal received: %i (%s), do exit.", signum,
        sigstr(signum).c_str());
    exit(signum);
}

int main(int argc, char **argv)
{
    signal(SIGINT, signal_handler);
    signal(SIGABRT, signal_handler);
    signal(SIGTERM, signal_handler);

    logger::Log &log = logger::Log::getInst();
    log.setLevel("DEBUG");

    if (argc < 2)
    {
        (void)argv;
        log.write(logger::INFO,
            "Config file not set. Using default configuration.");
    }
    Server webserv;
    webserv.Run();
}
