#pragma once

#include <vector>
#include <poll.h>

#define DEF_PORT "666"
#define LISTEN_BACKLOG 10

class Server
{
private:
    int m_ListeningSocket;
    std::vector<pollfd> m_SocketsPdfs;

public:
    Server();

    void Run();

private:
    void Init();
    void Listen();
    void AddToPdfs(int socket, std::vector<short> events);
    void DelFromPdfs(size_t deleted_idx);


    void *GetInputAddr(struct sockaddr *sa); /// for log
};
