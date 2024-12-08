#include <iostream>
#include <fstream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <chrono>

#pragma comment(lib, "Ws2_32.lib")

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
  WSADATA wsaData;
  SOCKET sock = INVALID_SOCKET;
  struct sockaddr_in serv_addr;
  char buffer[BUFFER_SIZE] = {0};

  // Initialize Winsock
  if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
  {
    std::cerr << "WSAStartup failed. Error Code: " << WSAGetLastError() << "\n";
    return -1;
  }

  // Create socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == INVALID_SOCKET)
  {
    std::cerr << "Socket creation failed. Error Code: " << WSAGetLastError() << "\n";
    WSACleanup();
    return -1;
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  // Convert address and connect
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  if (serv_addr.sin_addr.s_addr == INADDR_NONE)
  {
    std::cerr << "Invalid address or Address not supported.\n";
    closesocket(sock);
    WSACleanup();
    return -1;
  }

  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
    std::cerr << "Connection failed. Error Code: " << WSAGetLastError() << "\n";
    closesocket(sock);
    WSACleanup();
    return -1;
  }

  // Open file to send
  std::ifstream inFile("userdata.txt", std::ios::binary | std::ios::ate);
  if (!inFile)
  {
    std::cerr << "Failed to open file.\n";
    closesocket(sock);
    WSACleanup();
    return -1;
  }

  size_t fileSize = inFile.tellg();
  inFile.seekg(0);

  std::cout << "File size: " << fileSize << " bytes\n";

  // Send file data
  size_t totalSent = 0;
  auto startTime = std::chrono::high_resolution_clock::now();

  while (!inFile.eof())
  {
    inFile.read(buffer, BUFFER_SIZE);
    ssize_t bytesRead = inFile.gcount();
    if (send(sock, buffer, bytesRead, 0) == SOCKET_ERROR)
    {
      std::cerr << "Send failed. Error Code: " << WSAGetLastError() << "\n";
      break;
    }
    totalSent += bytesRead;

    // Print progress
    double percentage = (double)totalSent / fileSize * 100;
    auto currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = currentTime - startTime;

    double estimatedTime = elapsed.count() / (percentage / 100.0) - elapsed.count();
    std::cout << "\rProgress: " << percentage << "%, Estimated time left: " << estimatedTime << " seconds" << std::flush;
  }

  std::cout << "\nFile sent. Total bytes: " << totalSent << "\n";

  inFile.close();
  closesocket(sock);
  WSACleanup();
  return 0;
}
