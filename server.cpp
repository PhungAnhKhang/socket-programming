#include <iostream>
#include <sys/socket.h>
#include <sys/param.h>
#include <cstring>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define PORT 8080
#define BUFFER_SIZE 1000

int main() {
	freopen("out.txt", "w", stdout);
	int sid = socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in address;
	memset(&address, 0, sizeof(address));
	
	address.sin_family = AF_INET;
	address.sin_port = htons(PORT);
	address.sin_addr.s_addr = htonl(INADDR_ANY);

	int bc = bind(sid, (struct sockaddr *) &address, sizeof(address));
	listen(sid, 5);
	
	char message[BUFFER_SIZE];
	int clientSocket = accept(sid, (struct sockaddr *) NULL, NULL);
	while(true) {
		memset(message, 0, sizeof(message));
		int checkRead = recv(clientSocket, message, BUFFER_SIZE, 0);
		std::cout << message;
	}
	shutdown(clientSocket, 2);
	close(clientSocket);
	return 0;
}
