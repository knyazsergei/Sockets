#include "Sock.h"
#include <string>

using namespace std;

Sock::Sock(char ip[15], u_short port)
{
	cout << "Client: " << endl;

	WSAData wsa;
	WORD Version = MAKEWORD(2, 1);

	WSAStartup(Version, &wsa);

	if (WSAStartup(Version, &wsa) != 0)
	{

		cout << "Can't load WSA library." << endl;

	}
	else
	{

		cout << "WSA library load complite" << endl;

	}
	m_Connect = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_Connect == SOCKET_ERROR)
	{

		cout << "Can't create socket." << endl;

	}
	else
	{

		cout << "Socket create complite." << endl;

	}

	

	m_Client.sin_family = AF_INET;
	m_Client.sin_port = htons(port);
	m_Client.sin_addr.s_addr = inet_addr(ip);
}

void Sock::SendInfo(float first, float second)
{
	sprintf(m_pair, "%lf %lf", first, second);
	std::cout << "input send: " << m_pair << std::endl;
	
	while (1) // !!!
	{

		if (connect(m_Connect, (SOCKADDR*)&m_Client, sizeof(m_Client)))
		{

			cout << "Complite connect to server. " << m_pair << endl;

			send(m_Connect, m_pair, sizeof(m_pair), 0);
			recv(m_Connect, m_message, sizeof(m_message), 0);

			break;

		}

	}

	cout << "\n" << m_message << endl;

	closesocket(m_Connect);
	WSACleanup();
}

std::string Sock::ReturnAnswer()
{
	return std::string(m_message);
}
