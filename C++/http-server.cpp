#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

const int PORT = 8080;

void handleClient(int clientSocket) {
    const std::string httpResponse =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Connection: close\r\n"
        "\r\n"
        "<!DOCTYPE html>"
        "<html>"
        "<head><title>Simple HTTP Server</title></head>"
        "<body><h1>Welcome to the Simple HTTP Server!</h1></body>"
        "</html>";

    send(clientSocket, httpResponse.c_str(), httpResponse.size(), 0);
    close(clientSocket);
}

int main() {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Error: Failed to create socket.\n";
        return 1;
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Error: Binding failed.\n";
        close(serverSocket);
        return 1;
    }

    if (listen(serverSocket, 5) < 0) {
        std::cerr << "Error: Listening failed.\n";
        close(serverSocket);
        return 1;
    }

    std::cout << "HTTP server running on port " << PORT << "...\n";

    while (true) {
        sockaddr_in clientAddr{};
        socklen_t clientLen = sizeof(clientAddr);
        int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientLen);
        if (clientSocket < 0) {
            std::cerr << "Error: Accepting connection failed.\n";
            continue;
        }

        handleClient(clientSocket);
    }

    close(serverSocket);
    return 0;
}
