#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define TIMEOUT_SEC 1

void scan_port(const char *ip, int port) {
    int sock;
    struct sockaddr_in target;
    struct timeval timeout;
    fd_set fdset;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return;
    }

    timeout.tv_sec = TIMEOUT_SEC;
    timeout.tv_usec = 0;

    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    inet_pton(AF_INET, ip, &target.sin_addr);

    fcntl(sock, F_SETFL, O_NONBLOCK);

    connect(sock, (struct sockaddr *)&target, sizeof(target));

    FD_ZERO(&fdset);
    FD_SET(sock, &fdset);

    if (select(sock + 1, NULL, &fdset, NULL, &timeout) > 0) {
        int so_error;
        socklen_t len = sizeof(so_error);

        getsockopt(sock, SOL_SOCKET, SO_ERROR, &so_error, &len);
        if (so_error == 0) {
            printf("Port %d: OPEN\n", port);
        }
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <IP> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    const char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    printf("Scanning ports on %s from %d to %d...\n", ip, start_port, end_port);

    for (int port = start_port; port <= end_port; ++port) {
        scan_port(ip, port);
    }

    printf("Scan complete.\n");

    return 0;
}
