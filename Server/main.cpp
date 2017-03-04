// Server

#include <iostream>
#include <windows.h>
#include <winsock2.h>
#include <math.h>

using namespace std;

int main()
{
    
    cout << "Server: " << endl;
    
    char message[30];
    char result[30];
    float x, y, z, abs;
    
    WSAData wsa;
    WORD Version = MAKEWORD(2, 1);
    
    WSAStartup(Version, &wsa);
    
    if(WSAStartup(Version, &wsa) != 0)
    {
    
        cout << "WSA library startup error." << endl;
                           
    }
    else
    {
        
        cout << "WSA library startup complite." << endl;
        
    }
    
    SOCKET Listen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    SOCKET Connect = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    if(Listen == SOCKET_ERROR || Connect == SOCKET_ERROR)
    {
              
        cout << "Socket error. Can't create socket." << endl;
              
    }
    else
    {
        cout << "Socket create complite." << endl;
        
    }
    
    SOCKADDR_IN Server;
    
    Server.sin_family = AF_INET;
    Server.sin_port = htons(90);
    Server.sin_addr.s_addr = INADDR_ANY; // !!!
    
    if( bind(Listen, (SOCKADDR*)&Server, sizeof(Server)) == SOCKET_ERROR)
    {
        
        cout << "Can't bind socket." << endl;
        
    }
    else
    {
        
        cout << "Socket bind complite." << endl;
        
    }
    
    listen(Listen, SOMAXCONN);
    
    while(true)
    {
               
        if(Connect = accept(Listen, NULL, NULL))
        {
                   
            cout << "Client complite connected." << endl;
            
            recv(Connect, message, sizeof(message), 0);
            
            sscanf(message, "%f %f %f", &x, &y, &z);
            
            abs = sqrtf(x*x + y*y + z*z);
            
            sprintf(result, "Vector length: %lf\n", abs);
            
            send(Connect, result, MAX_PATH, 0);
            
            //break;
            
        }
        
        Sleep(100);
        
    }
    
    cout << "\n" << result << endl;
    
    ZeroMemory(message, sizeof(message));
    
    closesocket(Listen);
    closesocket(Connect);
    WSACleanup();
    system("pause");
    return 0;
    
}
