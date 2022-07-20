/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:25:12 by cflorind          #+#    #+#             */
/*   Updated: 2022/05/17 15:04:14 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.h"

srv::Server::Server(char **argv)
    : cfg_file(argv[1] ? argv[1] : DEFCFG)
{
    this->parseCfg();
}

srv::Server::~Server(void){};

srv::t_ports &srv::Server::operator[](const in_addr_t &key)
{
    logger::Log &log = logger::Log::getInst();
    log(logger::DEBUG, "srv::Server::operator[]: Getting server: %s",
        srv::ntoa(key));
    return (this->srvs[key]);
}

srv::t_srvs::iterator    srv::Server::find(const in_addr_t &key)
{
    logger::Log &log = logger::Log::getInst();
    log(logger::DEBUG, "srv::Server::find: Finding server: %s", srv::ntoa(key));
    return (this->srvs.find(key));
}

srv::t_srvs::iterator    srv::Server::begin(void)
{
    return (this->srvs.begin());
}

srv::t_srvs::iterator    srv::Server::end(void)
{
    return (this->srvs.end());
}

srv::Cfg::~Cfg(void)
{
    std::set<t_cfgs *>      deleted;
    t_name_srvs::iterator   it;
    logger::Log &log = logger::Log::getInst();

    for (it = this->name_srvs.begin(); it != this->name_srvs.end(); ++it)
    {
        if (deleted.find(it->second) == deleted.end())
        {
            deleted.insert(it->second);
            log(logger::DEBUG, "srv::Cfg::~Cfg: Deleted server configs: %p",
                it->second);
            delete it->second;
        }
    }
}

srv::t_cfgs   &srv::Cfg::operator[](const std::string &key)
{
    t_name_srvs::iterator it;
    logger::Log &log = logger::Log::getInst();

    it = this->name_srvs.find(key);
    if (it == this->name_srvs.end())
    {
        log(logger::DEBUG,
            "srv::Cfg::operator[]: Name_server: %s not found, creating new one.",
                key.c_str());
        this->name_srvs[key] = new srv::t_cfgs;
        log(logger::DEBUG,
            "srv::Cfg::operator[]: New name_server: %s, created at %p.",
                key.c_str(), this->name_srvs[key]);
    }
    return (*this->name_srvs[key]);
}

srv::t_cfgs   &srv::Cfg::addAlterName(
    const std::string &name_server, const std::string &alter_name_server)
{
    t_name_srvs::iterator it;
    logger::Log &log = logger::Log::getInst();

    it = this->name_srvs.find(name_server);
    if (it == this->name_srvs.end())
    {
        log(logger::DEBUG, "srv::Cfg::addAlterName: For alter_name: %s\
name_server: %s not found, creating new one.",
                alter_name_server.c_str(), name_server.c_str());
        this->name_srvs[name_server] = new srv::t_cfgs;
        log(logger::DEBUG,
            "srv::Cfg::addAlterName: New name_server: %s, created at %p.",
                name_server.c_str(), this->name_srvs[name_server]);
    }
    this->name_srvs[alter_name_server] = this->name_srvs[name_server];
    log(logger::DEBUG, "srv::Cfg::addAlterName: New name_server: %s, \
at %p. Alter name_server: %s, at %p",
            name_server.c_str(), this->name_srvs[name_server],
            alter_name_server.c_str(), this->name_srvs[alter_name_server]);
    return (*this->name_srvs[alter_name_server]);
}

void    srv::Server::parseCfg(void)
{
    logger::Log &log = logger::Log::getInst();
    log(logger::INFO,
        "srv::Server::parseCfg: Getting configuration from file: %s",
        this->cfg_file.c_str());
    this->srvs[aton("127.0.0.1")][80].addAlterName("localhost", "alterhost");
    this->srvs[aton("127.0.0.1")][80]["alterhost"]["server"]
                ["listen_addr"] = "127.0.0.1";
    this->srvs[aton("127.0.0.1")][80]["alterhost"]["server"]
                ["server_name"] = "localhost";
    this->srvs[aton("127.0.0.1")][80]["alterhost"]["/docs/"]
                ["root"] = "./usr/docs";
    this->srvs[aton("127.0.0.1")][80]["testhost"]["server"]
                ["server_name"] = "testhost";
}
