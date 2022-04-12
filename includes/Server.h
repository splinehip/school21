#pragma once

#include <vector>
#include <poll.h>
#include <sys/socket.h>
//#include <unordered_map>
#include <deque>
#include <cstdlib>
#include <unistd.h>
#include <errno.h>

#include "Logger/Logger.hpp"
#include "VirtualServer.h"

#define DEF_PORT "8080"
#define LISTEN_BACKLOG 10

class Server
{
private:
    static const short ReadEvent[1];
    static const short WriteEvent[1];
    static const short ReadWriteEvent[2];

    int m_ListeningSocket;
    std::vector<pollfd> m_SocketsPdfs;

    /*std::unordered_map<short, std::deque<VirtualServer>> m_VirtualServers;*/ /// заполняется из конфига: порт в виртуальные сервера
    /*std::unordered_map<short, int> m_PortToSocket;*/ /// соответсиве виртуального порта в файловый дескриптор (видимо из Request формируется)

    /**
     * \todo
     * \details HttpManager отвечает за парсинг принятоой строки из recv. Возможно будет один инстанс на процесс
     *      Из него мы получаем, на какой виртуальный сервер отправлен запрос, от какого клиента (по всей видимости)
     *      Один из методов должен возвращать некий класс HttpRequest, сохраняемый для клиента
     */
    /*Http::HttpManager& m_HttpManager;*/
public:
    Logger             log;

public:
    Server();

    /*Server(const Config& conf);*/ /// вместо дефолтного конструктора в дальнейшем

    void Run();

private:
    void ReceiveRequest(int readable_socket, size_t socket_index);
    void SendResponse(int sendable_socket);

    void Init();
    void AddToPdfs(int socket, const short *events, size_t events_size);
    void DelFromPdfs(std::size_t deleted_idx);

    void *GetInputAddr(sockaddr *sa) const;
    std::string GetPrintableIP(sockaddr *addr_info) const;
};
