#include <arpa/inet.h> // inet_addr()
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> // bzero()
#include <sys/socket.h>
#include <unistd.h> // read(), write(), close()

void func(int sockfd)
{
	char buff1[80],buff2[80];
	for (;;) { 
		printf("Enter the string : ");
		scanf("%s",buff1);
		write(sockfd, buff1, sizeof(buff1));
		read(sockfd, buff2, sizeof(buff2));
		printf("From Server : %s\n", buff2);
		if(strncmp(buff2,"exit",4)==0)
			break;
	}
}

int main()
{
	int sockfd, connfd;
	struct sockaddr_in servaddr, cli;

	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	// if (sockfd == -1) {
	// 	printf("socket creation failed...\n");
	// 	exit(0);
	// }
	// else
	// 	printf("Socket successfully created..\n");
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	// servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(8080);

	// connect the client socket to server socket
	// if (
	connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
	// 	!= 0) {
	// 	printf("connection with the server failed...\n");
	// 	exit(0);
	// }
	// else
	// 	printf("connected to the server..\n");

	// function for chat
	func(sockfd);

	// close the socket
	close(sockfd);
}

