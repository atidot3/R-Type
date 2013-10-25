#ifndef SOCKETWINDOWS
# define SOCKETWINDOWS

#pragma comment(lib, "ws2_32.lib")
#include <iostream>
#include <string>
#include "server.hpp"
#include "log.hpp"
#include <windows.h>
#include "sockets/iSocket.hpp"

class SocketWindows : public ISocket
{
public:
    SocketWindows(const std::string, int, const std::string mode = "UDP");
    SocketWindows(int, int = 42, const std::string mode = "UDP");
    SocketWindows(SOCKET, SOCKADDR_IN);
    virtual ~SocketWindows();

    void connect();
    ISocket* accept();
    void send(const std::string&, std::string ip = "", int port = 0);
	std::string recv(int, std::string* ip = NULL);

private:
    void bind();
    void listen(int);

    SOCKET          hSocket;
    SOCKADDR_IN     hSin;
    std::string     hMode;
};

#ifdef WIN32
typedef SocketWindows AbstractSocket;
#endif

#endif //SOCKETWINDOWS
