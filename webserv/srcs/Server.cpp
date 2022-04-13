#include "Server.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <cstring>
#include <arpa/inet.h>

#include <iostream>

#define POLL_TIMEOUT -1

static logger::Log &log = logger::Log::inst();

const short Server::ReadEvent[1] = {POLLIN};
const short Server::WriteEvent[1] = {POLLOUT};
const short Server::ReadWriteEvent[2] = {POLLIN, POLLOUT};

Server::Server()
{
    Init();
    AddToPdfs(m_ListeningSocket, Server::ReadEvent, sizeof(Server::ReadEvent));
}

void Server::Run()
{
    while(true)
    {
        int poll_cnt = poll(m_SocketsPdfs.data(), m_SocketsPdfs.size(), POLL_TIMEOUT);

        if (poll_cnt == -1)
        {
            log.write(ERROR, "poll: ", strerror(errno));
            exit(EXIT_FAILURE);
        }

        for (size_t i = 0, visited = 0; i < m_SocketsPdfs.size(); ++i)
        {
            if (m_SocketsPdfs[i].revents == 0)
            {
                continue;
            }
            if (m_SocketsPdfs[i].revents & POLLIN)
            {
                ReceiveRequest(m_SocketsPdfs[i].fd, i);
            }
            if (m_SocketsPdfs[i].revents & POLLOUT)
            {
                SendResponse(m_SocketsPdfs[i].fd);
            }
            ++visited;
            if (static_cast<int>(visited) == poll_cnt)
            {
                break;
            }
        }
    }
}

void Server::ReceiveRequest(int readable_socket, size_t socket_index)
{
    if (readable_socket == m_ListeningSocket)
    {
        sockaddr_storage connecting_address = {};
        socklen_t storage_size = sizeof(connecting_address);
        int connected_socket = accept(m_ListeningSocket, reinterpret_cast<sockaddr*>(&connecting_address), &storage_size);
        if (connected_socket == -1)
        {
            log.write(ERROR, "accept: %s", strerror(errno));
        }
        else
        {
            AddToPdfs(connected_socket, Server::ReadWriteEvent, sizeof(Server::ReadWriteEvent));

            log.write(INFO, "New connection from %s with socket %i remote\
address family: %s",
                GetPrintableIP(reinterpret_cast<sockaddr*>(&connecting_address)).c_str(),
                connected_socket,
                (connecting_address.ss_family == AF_INET ? "IPv4" : "IPv6"));
        }
    }
    else
    {
        char rec_buf[512];
        int bytes_cnt = recv(readable_socket, rec_buf, sizeof(rec_buf), 0);
        if (bytes_cnt <=  0)
        {
            if (bytes_cnt == 0)
            {
                log.write(INFO, "Socket %i closed connection",
                    readable_socket);
            }
            else if (bytes_cnt == -1)
            {
                log.write(ERROR, "recv: %s", strerror(errno));
            }
            close(readable_socket);
            DelFromPdfs(socket_index);
        }
        else
        {
            /// Parse Request
            /// Transfer to VirtualServer
        }
    }
}

void Server::SendResponse(int sendable_socket)
{
    /// Check Response and send
    if (send(sendable_socket, "Hello", 5, 0) == -1)
    {
        log.write(ERROR, "send: %s", strerror(errno));
    }
}

void Server::Init()
{
    addrinfo hints = {};
    hints.ai_family = AF_UNSPEC; /// auto determining IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE; /// use my IP address as host. Write INADDR_ANY to IP address

    addrinfo *results;
    int rv;
    if ((rv = getaddrinfo(NULL, DEF_PORT, &hints, &results)) != 0)
    {
        log.write(ERROR, "Getaddrinfo error: %s", gai_strerror(rv));
        exit(EXIT_FAILURE);
    }

    addrinfo *curr;
    for (curr = results; curr != NULL; curr = curr->ai_next)
    {
        if ((m_ListeningSocket = socket(
            curr->ai_family, curr->ai_socktype, curr->ai_protocol)) == -1)
        {
            log.write(ERROR, "socket: %s", strerror(errno));
            continue;
        }

        int yes = 1; /// may be need char for Sun and Win
        if (setsockopt(m_ListeningSocket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1) /// skip "Address already in use" when old socket wasn't closed
        {
            log.write(ERROR, "setsockopt: %s", strerror(errno));
            exit(EXIT_FAILURE);
        }

        if (bind(m_ListeningSocket, curr->ai_addr, curr->ai_addrlen) == -1)
        {
            log.write(ERROR, "bind: %s", strerror(errno));
            continue;
        }
        break;
    }

    if (curr == NULL)
    {
        log.write(ERROR, "Error getting listening socket");
        exit(EXIT_FAILURE);
    }

    log.write(INFO,
        "Host ip: %s; Cannon name: %s; host address family: %s",
        GetPrintableIP(curr->ai_addr).c_str(), curr->ai_canonname,
        (curr->ai_family == AF_INET ? "IPv4" : "IPv6"));

    freeaddrinfo(results);

    if (listen(m_ListeningSocket, LISTEN_BACKLOG) == -1)
    {
       log.write(ERROR, "listen: %s", strerror(errno));
        exit(EXIT_FAILURE);
    }
}

std::string Server::GetPrintableIP(sockaddr *addr_info) const
{
    static char ip[INET6_ADDRSTRLEN];
    return inet_ntop(addr_info->sa_family, GetInputAddr(addr_info), ip, sizeof(ip));
}

void Server::AddToPdfs(int socket, const short *events, size_t events_size)
{
    pollfd inserting = {};
    inserting.fd = socket;

    for (size_t i = 0; i < events_size; ++i)
    {
        inserting.events |= events[i];
    }

    m_SocketsPdfs.push_back(inserting);
}

void Server::DelFromPdfs(size_t deleted_idx)
{
    m_SocketsPdfs.erase(m_SocketsPdfs.begin() + deleted_idx);
}

void *Server::GetInputAddr(sockaddr *sa) const
{
    if (sa->sa_family == AF_INET)
    {
        return &(reinterpret_cast<sockaddr_in*>(sa)->sin_addr);
    }
    return &(reinterpret_cast<sockaddr_in6*>(sa)->sin6_addr);
}
