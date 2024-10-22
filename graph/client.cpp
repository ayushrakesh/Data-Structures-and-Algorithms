#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "Ws2_32.lib")

using namespace std;

int main()
{
  WSADATA wsa;
  SOCKET cst;
  sockaddr_in sdr;

  if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
  {
    cerr << "WSAStartup failed.\n";
    return 1;
  }

  cst = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (cst == INVALID_SOCKET)
  {
    cerr << "Socket creation failed.\n";
    WSACleanup();
    return 1;
  }

  sdr.sin_family = AF_INET;
  sdr.sin_addr.s_addr = inet_addr("127.0.0.1");
  sdr.sin_port = htons(8080);

  if (connect(cst, (sockaddr *)&sdr, sizeof(sdr)) == SOCKET_ERROR)
  {
    cerr << "Connection to server failed.\n";
    closesocket(cst);
    WSACleanup();
    return 1;
  }

  string msg = "Hello from Ayush!";
  send(cst, msg.c_str(), msg.size(), 0);

  closesocket(cst);
  WSACleanup();

  return 0;
}