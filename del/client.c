#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<strings.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<stdlib.h>
int main()
{
    int clientsocket,port; //clientsocket is the socket descriptor , port is the port number
    struct sockaddr_in serveraddr; //creating a structure of type sockaddr_in for server
    socklen_t len; //creating a variable to store the length of the server address
    char message[50];
    char send[50];
    char recvline[50];


    clientsocket=socket(AF_INET,SOCK_STREAM,0);//creating a socket
    bzero((char*)&serveraddr,sizeof(serveraddr));//initializing the server address to zero
    len=sizeof(serveraddr); //storing the length of the server address in len
    serveraddr.sin_family=AF_INET; //setting the family of the server address to AF_INET

    printf("Enter the port number ");
    scanf("%d",&port);
    serveraddr.sin_port=htons(port);//setting the port number of the server address to port
    printf("\nTrying to connect to the server.\n");


    connect(clientsocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));//connecting to the server
    printf("\nConnected to the server.\n");
    printf("Enter file name");
    scanf("%s",send);
    write(clientsocket,send,sizeof(send));
    while(read(clientsocket,recvline,sizeof(recvline))!=0)
    {
      printf("%s",recvline);
    }
    close(clientsocket);
}