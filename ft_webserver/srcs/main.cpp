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

    std::string configFile = "defaultConfig";

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
    else
    {
        log(logger::INFO,
            "Next config will use: %s", argv[1]);
        configFile = argv[1];
    }
    in_addr addr;
    srv::m_srvs_t srvs = srv::initServers(configFile);
    srv::m_srvs_t::iterator it = srvs.begin();
    while (it != srvs.end())
    {
        addr.s_addr = it->first;
        std::cout << "ip: " << inet_ntoa(addr);

        srv::m_srv_t::iterator it2 = it->second.begin();
        while (it2 != it->second.end())
        {
            std::cout << "\n\tport: " << ntohs(it2->first) << "\n\t\t";
            srv::cfgs_t::iterator it3 = it2->second.cfgs.begin();
            while (it3 != it2->second.cfgs.end())
            {
                //cfg::error_pages_t ep = it3->error_pages;
                //std::cout << "error_pages\n" << ep[500] << std::endl;
                cfg::server_names_t::iterator snit = it3->server_names.begin();
                std::cout << "server_names: ";
                while (snit != it3->server_names.end())
                {
                    std::cout << *snit++ << " ";
                }
                std::cout << std::endl;
                cfg::location_t::const_iterator it4 = it3->locs.begin();
                while (it4 != it3->locs.end())
                {
                    std::cout << "location: " << it4->first << ", ";
                    std::cout << "index: " << it4->second.index << std::endl;
                    it4++;
                }
                it3++;
            }
            it2++;
        }
        it++;
    }
    std::cout << "server 127.0.0.1:8080 id = "
        << srvs[inet_aton("127.0.0.1", &addr)][8080]["test_server"].id
        << std::endl;
    return (0);
}
