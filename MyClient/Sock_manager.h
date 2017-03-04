#pragma once
#include "Sock.h"
using namespace System;

ref class Sock_manager
{
private:
	Sock * m_sock;

public:
	Sock_manager();
	void Init(System::String ^ ip, System::String ^ port);
	~Sock_manager();
	void SendInfo(System::String ^ first, System::String ^ second);
	System::String ^ ReturnAnswer();
};

