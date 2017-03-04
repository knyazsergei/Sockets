#pragma once

#include <winsock2.h> 
#include <ws2tcpip.h>
#include <string>
#include <iostream>
#pragma comment(lib, "ws2_32.lib")


class Sock
{
public:
	Sock(char ip[15], u_short port);
	void SendInfo(float first, float second);
	std::string ReturnAnswer();
private:
	SOCKET m_Connect = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKADDR_IN m_Client;

	char m_pair[20];
	char m_message[30] = "error connect";
};

