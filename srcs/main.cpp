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
    }
    cfg::Config cfg;
    cfg.locs["/"] = cfg::Location();
    cfg.locs["/"].index_fd = open("README.md", O_RDONLY);
    fstat(cfg.locs["/"].index_fd, &cfg.locs["/"].index_fd_st);
    utl::readFileToString(cfg.locs["/"].index_fd, cfg.locs["/"].index);
    std::cout << "index\n" << cfg.getLocIndex(cfg.locs.find("/")) << std::endl;
    sleep(5);
    std::cout << "second\n" << cfg.getLocIndex(cfg.locs.find("/")) << std::endl;

    return (0);
}
