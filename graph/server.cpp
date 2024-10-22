#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "Ws2_32.lib")

using namespace std;

int main()
{
  WSADATA wsa;
  SOCKET sst, cst;
  sockaddr_in sdr, cdr;
  int cds = sizeof(cdr);

  if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
  {
    cerr << "WSAStartup failed.\n";
    return 1;
  }

  sst = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (sst == INVALID_SOCKET)
  {
    cerr << "Socket creation failed.\n";
    WSACleanup();
    return 1;
  }

  sdr.sin_family = AF_INET;
  sdr.sin_addr.s_addr = INADDR_ANY;
  sdr.sin_port = htons(8080);

  if (bind(sst, (sockaddr *)&sdr, sizeof(sdr)) == SOCKET_ERROR)
  {
    cerr << "Bind failed.\n";
    closesocket(sst);
    WSACleanup();
    return 1;
  }

  if (listen(sst, SOMAXCONN) == SOCKET_ERROR)
  {
    cerr << "Listen failed.\n";
    closesocket(sst);
    WSACleanup();
    return 1;
  }

  cout << "Server listening on port 8080...\n";

  cst = accept(sst, (sockaddr *)&cdr, &cds);
  if (cst == INVALID_SOCKET)
  {
    cerr << "Accept failed.\n";
    closesocket(sst);
    WSACleanup();
    return 1;
  }

  char buf[1024];
  int btr = recv(cst, buf, sizeof(buf), 0);
  if (btr > 0)
  {
    cout << "Received message from client: " << string(buf, 0, btr) << "\n";
  }

  closesocket(cst);
  closesocket(sst);
  WSACleanup();

  return 0;
}