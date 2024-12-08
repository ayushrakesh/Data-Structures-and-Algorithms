#include <iostream>
#include <fstream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
  WSADATA wsaData;
  SOCKET server_fd = INVALID_SOCKET, new_socket = INVALID_SOCKET;
  struct sockaddr_in address;
  int addrlen = sizeof(address);
  char buffer[BUFFER_SIZE] = {0};

  // Initialize Winsock
  if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
  {
    std::cerr << "WSAStartup failed. Error Code: " << WSAGetLastError() << "\n";
    return -1;
  }

  // Create socket
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd == INVALID_SOCKET)
  {
    std::cerr << "Socket creation failed. Error Code: " << WSAGetLastError() << "\n";
    WSACleanup();
    return -1;
  }

  // Bind to port
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == SOCKET_ERROR)
  {
    std::cerr << "Bind failed. Error Code: " << WSAGetLastError() << "\n";
    closesocket(server_fd);
    WSACleanup();
    return -1;
  }

  // Listen for incoming connections
  if (listen(server_fd, 3) == SOCKET_ERROR)
  {
    std::cerr << "Listen failed. Error Code: " << WSAGetLastError() << "\n";
    closesocket(server_fd);
    WSACleanup();
    return -1;
  }
  std::cout << "Waiting for connection...\n";

  // Accept a connection
  new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);
  if (new_socket == INVALID_SOCKET)
  {
    std::cerr << "Accept failed. Error Code: " << WSAGetLastError() << "\n";
    closesocket(server_fd);
    WSACleanup();
    return -1;
  }
  std::cout << "Connection established.\n";

  // Receive file
  std::ofstream outFile("received_userdata.txt", std::ios::binary);
  if (!outFile)
  {
    std::cerr << "File creation failed.\n";
    closesocket(new_socket);
    closesocket(server_fd);
    WSACleanup();
    return -1;
  }

  size_t totalReceived = 0;
  int bytesRead;
  while ((bytesRead = recv(new_socket, buffer, BUFFER_SIZE, 0)) > 0)
  {
    outFile.write(buffer, bytesRead);
    totalReceived += bytesRead;
  }

  std::cout << "File received. Total bytes: " << totalReceived << "\n";

  outFile.close();
  closesocket(new_socket);
  closesocket(server_fd);
  WSACleanup();
  return 0;
}
