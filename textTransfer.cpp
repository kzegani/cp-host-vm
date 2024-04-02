#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main() {
	int server_fd = -1, new_socket = -1;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[1024] = {0};
	const int Port = 13423;

	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket failed");
		exit(1);
	}

	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
		perror("setsockopt");
		exit(1);
	}

	address.sin_family = AF_INET;
	address.sin_port = htons(Port);
	address.sin_addr.s_addr = INADDR_ANY;

	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
		perror("bind failed");
		exit(1);
	}

	if (listen(server_fd, 3) < 0) {
		perror("listen failed");
		exit(1);
	}

	if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
		perror("accept");
		exit(1);
	}

	ssize_t n_read = read(new_socket, buffer, 1023);

	buffer[n_read] = '\0';
	if (n_read > 0) {
		std::cout << "Recaived: " << buffer << std::endl ;
	} else if (n_read == 0) {
		std::cout << "The client closed the connection" << std::endl ;
	} else {
		perror("read");
	}

	close(server_fd);
	close(new_socket);

	return 0;
}