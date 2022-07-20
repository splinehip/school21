#include <iostream>
#include <csignal>

#include "Server.h"
#include "logger/Log.h"

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
    srv::Server  srv(argv);
    std::cout
        << "127.0.0.1:80:localhost:listen_addr: "
        << srv[srv::aton("127.0.0.1")][80]["localhost"]["server"]["listen_addr"]
        << "\n127.0.0.1:80:localhost:server_name: "
        << srv[srv::aton("127.0.0.1")][80]["localhost"]["server"]["server_name"]
        << "\n127.0.0.1:80:alterhost:server_name: "
        << srv[srv::aton("127.0.0.1")][80]["alterhost"]["server"]["server_name"]
        << "\n127.0.0.1:80:localhost:loc: "
        << srv[srv::aton("127.0.0.1")][80]["localhost"].find("/docs/")->first
        << srv[srv::aton("127.0.0.1")][80]["localhost"]["/docs/"]["root"]
        << std::endl;
    std::cout
        << "127.0.0.1:80::testhost:server_name: "
        << srv[srv::aton("127.0.0.1")][80]["testhost"]["server"]["server_name"]
        << std::endl;
    srv[srv::aton("127.0.0.1")][443]["localhost"]["server"]["listen_addr"]
                                                                = "127.0.0.1";
    std::cout
        << "127.0.0.1:443:localhost:listen_addr: "
        << srv[srv::aton("127.0.0.1")][443]["localhost"]["server"]["listen_addr"]
        << std::endl;
    srv::t_srvs::iterator s = srv.find(srv::aton("127.0.0.1"));
    if (s != srv.end())
    {
        std::cout << srv::ntoa(s->first) << ":" << std::endl;
        for (srv::t_ports::iterator ns
                = s->second.begin(); ns != s->second.end(); ns++)
        {
            std::cout << "\t" << ns->first << std::endl;
        }
    }
    return (0);
}
