#pragma once

#include <vector>

#include "ClientConnection.h"
#include "raii_ptr.h"

class VirtualServerBuilder;

class VirtualServer
{
private:
    std::string m_Port;
    std::string m_HostIP;
    std::string m_ServerName;
    std::vector<ClientConnection> m_Connections;

private:
    VirtualServer() {}

    friend class VirtualServerBuilder;
public:
    void AddConnection(const ClientConnection& client_connection)
    {
        m_Connections.push_back(client_connection);
    }
};

class VirtualServerBuilder
{
private:
    VirtualServerBuilder(/*const Config& config*/)
//        : m_Config(config)
    {}

private:
    VirtualServer m_VS;
//    const Config& m_Config;

public:
    operator VirtualServer()
    {
        return m_VS;
    }

    static VirtualServerBuilder Build(/*const Config& config*/)
    {
        return VirtualServerBuilder(/*config*/);
    }

    VirtualServerBuilder& AddServerPort()
    {
//        m_VS.m_Port = m_Config.GetPort();
        return *this;
    }

    VirtualServerBuilder& AddHostIP()
    {
//        m_VS.m_HostIP = m_Config.GetHostIP();
        return *this;
    }

    VirtualServerBuilder& AddServerName()
    {
//        m_VS.m_ServerName = m_Config.GetServerName();
        return *this;
    }
};
