#include "Sock_manager.h"
#include <msclr/marshal.h>
#include <string.h>
using namespace msclr::interop;


Sock_manager::Sock_manager()
{
	
}

void Sock_manager::Init(System::String ^ ip, System::String ^ port)
{
	marshal_context^ marshal = gcnew marshal_context();
	const char* prIp = marshal->marshal_as<const char*>(ip);
	char resultIp[15];
	strncpy(resultIp, prIp, 15);

	m_sock = new Sock(resultIp, System::Convert::ToInt32(port));
}

Sock_manager::~Sock_manager()
{
	delete m_sock;
}

void Sock_manager::SendInfo(System::String ^ first, System::String ^ second)
{
	
	float mfirst = Convert::ToDouble(first);
	float msecond = Convert::ToDouble(second);
	
	m_sock->SendInfo(mfirst, msecond);
}

System::String ^ Sock_manager::ReturnAnswer()
{
	return msclr::interop::marshal_as<String^>(m_sock->ReturnAnswer().c_str());
}
