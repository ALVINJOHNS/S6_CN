#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h> // read(), write(), close()
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 

// Function designed for chat between client and server. 
void func(int connfd) 
{ 
	char buff1[80],buff2[80]; 
	for (;;) { 
		read(connfd, buff2, sizeof(buff2));
		printf("From Client : %s\n", buff2);
		printf("Enter the string : ");
		scanf("%s",buff1);
		write(connfd, buff1, sizeof(buff1));
		if(strncmp(buff2,"exit",4)==0)
			break;
	}
} 

// Driver function 
int main() 
{ 
	int sockfd, connfd, len; 
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
	servaddr.sin_addr.s_addr = INADDR_ANY; 
	servaddr.sin_port = htons(PORT); 

	// Binding newly created socket to given IP and verification 
	// if (
		(bind(sockfd, (SA*)&servaddr, sizeof(servaddr)));
	// 	 != 0) { 
	// 	printf("socket bind failed...\n"); 
	// 	exit(0); 
	// } 
	// else
	// 	printf("Socket successfully binded..\n"); 

	// Now server is ready to listen and verification 
	//if (
		(listen(sockfd, 5)) ;
	// 	!= 0) { 
	// 	printf("Listen failed...\n"); 
	// 	exit(0); 
	// } 
	// else
	// 	printf("Server listening..\n"); 
	len = sizeof(cli); 

	// Accept the data packet from client and verification 
	connfd = accept(sockfd, (SA*)&cli, &len); 
	// if (connfd < 0) { 
	// 	printf("server accept failed...\n"); 
	// 	exit(0); 
	// } 
	// else
	// 	printf("server accept the client...\n"); 

	// Function for chatting between client and server 
	func(connfd); 

	// After chatting close the socket 
	close(sockfd); 
}

