#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <sys/param.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define PORT 8080
#define BUFFER_SIZE 1000

int main() {
    int sid = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("192.168.122.105");


    char message[BUFFER_SIZE];
    int cc = connect(sid, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
    std::cout << message;
    while(true) {
        memset(message, 0, sizeof(message));
        fgets(message, BUFFER_SIZE, stdin);
        send(sid, message, BUFFER_SIZE, 0);
    }
    shutdown(sid, 2);
    close(sid);
    return 0;
}