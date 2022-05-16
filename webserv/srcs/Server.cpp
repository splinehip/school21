/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:25:12 by cflorind          #+#    #+#             */
/*   Updated: 2022/05/16 18:39:53 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.h"

Server::Server(char **argv)
    : cfg_file(argv[1] ? argv[1] : DEFCFG)
{
    this->parseCfg();
}

Server::~Server(void){};

Server::Cfg::~Cfg(void)
{
    std::set<Server::t_cfgs *>       deleted;
    t_name_srvs::iterator   it;

    for (it = this->name_srvs.begin(); it != this->name_srvs.end(); ++it)
    {
        if (deleted.find(it->second) == deleted.end())
        {
            deleted.insert(it->second);
            delete it->second;
        }
    }
}

Server::t_cfgs   &Server::Cfg::operator[](const std::string &key)
{
    t_name_srvs::iterator it;

    it = this->name_srvs.find(key);
    if (it == this->name_srvs.end())
    {
        this->name_srvs[key] = new Server::t_cfgs;
    }
    return (*this->name_srvs[key]);
}

Server::t_cfgs   &Server::Cfg::addAlterName(
    const std::string &name_server, const std::string &alter_name_server)
{
    t_name_srvs::iterator it;

    it = this->name_srvs.find(name_server);
    if (it == this->name_srvs.end())
    {
        this->name_srvs[name_server] = new Server::t_cfgs;
    }
    this->name_srvs[alter_name_server] = this->name_srvs[name_server];
    return (*this->name_srvs[alter_name_server]);
}

void    Server::parseCfg(void)
{
    logger::Log &log = logger::Log::getInst();
    log(logger::INFO, "Using configuration file: %s", this->cfg_file.c_str());
    this->srvs[aton("127.0.0.1")][80].addAlterName("localhost", "alterhost");
    this->srvs[aton("127.0.0.1")][80]["alterhost"]["server"]
                ["listen_addr"] = "127.0.0.1";
    this->srvs[aton("127.0.0.1")][80]["alterhost"]["server"]
                ["server_name"] = "localhost";
    this->srvs[aton("127.0.0.1")][80]["alterhost"]["/docs/"]
                ["root"] = "./usr/docs";
    this->srvs[aton("127.0.0.1")][80]["testhost"]["server"]
                ["server_name"] = "testhost";
    std::cout
        << "127.0.0.1:80:localhost:listen_addr: "
        << this->srvs[aton("127.0.0.1")][80]["localhost"]["server"]
                    ["listen_addr"]
        << "\n127.0.0.1:80:localhost:server_name: "
        << this->srvs[aton("127.0.0.1")][80]["localhost"]["server"]
                    ["server_name"]
        << "\n127.0.0.1:80:alterhost:server_name: "
        << this->srvs[aton("127.0.0.1")][80]["alterhost"]["server"]
                    ["server_name"]
        << "\n127.0.0.1:80:localhost:loc: "
        << this->srvs[aton("127.0.0.1")][80]["localhost"].find("/docs/")->first
        << this->srvs[aton("127.0.0.1")][80]["localhost"]["/docs/"]["root"]
        << std::endl;
    std::cout << "127.0.0.1:80::testhost:server_name: "
        << this->srvs[aton("127.0.0.1")][80]["testhost"]["server"]["server_name"]
        << std::endl;
    this->srvs[aton("127.0.0.1")][443]["localhost"]["server"]
                    ["listen_addr"] = "127.0.0.1";
    std::cout
        << "127.0.0.1:443:localhost:listen_addr: "
        << this->srvs[aton("127.0.0.1")][443]["localhost"]["server"]
                    ["listen_addr"] << std::endl;
    t_srvs::iterator srv = this->srvs.find(aton("127.0.0.1"));
    if (srv != this->srvs.end())
    {
        std::cout << ntoa(srv->first) << ":" << std::endl;
        for (t_listen_ports::iterator nsrv
                = srv->second.begin(); nsrv != srv->second.end(); nsrv++)
        {
            std::cout << "\t" << nsrv->first << std::endl;
        }
    }

}
