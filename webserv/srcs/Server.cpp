/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:25:12 by cflorind          #+#    #+#             */
/*   Updated: 2022/05/11 23:52:12 by cflorind         ###   ########.fr       */
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
    std::set<t_cfg *>       deleted;
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

Server::t_cfg   &Server::Cfg::operator[](const std::string &key)
{
    t_name_srvs::iterator it;

    it = this->name_srvs.find(key);
    if (it == this->name_srvs.end())
    {
        this->name_srvs[key] = new t_cfg;
    }
    return (*this->name_srvs[key]);
}

Server::t_cfg   &Server::Cfg::addAlterName(
    const std::string &name_server, const std::string &alter_name_server)
{
    t_name_srvs::iterator it;

    it = this->name_srvs.find(name_server);
    if (it == this->name_srvs.end())
    {
        this->name_srvs[name_server] = new t_cfg;
    }
    this->name_srvs[alter_name_server] = this->name_srvs[name_server];
    return (*this->name_srvs[alter_name_server]);
}

void    Server::parseCfg(void)
{
    logger::Log &log = logger::Log::getInst();
    log(logger::INFO, "Using configuration file: %s", this->cfg_file.c_str());
    this->srvs[aton("127.0.0.1")][80].addAlterName("localhost", "alterhost");
    this->srvs
        [aton("127.0.0.1")][80]["alterhost"]["listen_addr"] = "127.0.0.1";
    this->srvs[aton("127.0.0.1")][80]["alterhost"]["server_name"] = "localhost";
    this->srvs[aton("127.0.0.1")][80]["testhost"]["listen_addr"] = "127.0.0.2";
    std::cout
        << "localhost:listen_addr: "
        << this->srvs[aton("127.0.0.1")][80]["localhost"]["listen_addr"]
        << "\nlocalhost:server_name: "
        << this->srvs[aton("127.0.0.1")][80]["localhost"]["server_name"]
        << std::endl;
    std::cout << "testhost:listen_addr: "
        << this->srvs[aton("127.0.0.1")][80]["testhost"]["listen_addr"]
        << std::endl;
    std::cout << ntoa(this->srvs.find(aton("127.0.0.1"))->first) << std::endl;
    t_srvs::iterator srvs = this->srvs.find(aton("127.0.0.1"));
    if (srvs != this->srvs.end())
        std::cout << ntoa(srvs->first) << std::endl;

}
