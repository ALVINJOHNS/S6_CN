#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void main(){
    int sockfd,len;
    char ss[10];
    struct sockaddr_in server, client;
    len=sizeof(client);
    sockfd= socket(AF_INET,SOCK_DGRAM,0);
    bzero((struct sockaddr*)&server ,sizeof(server));
    server.sin_family=AF_INET;
    server.sin_port=htons(2000);
    server.sin_addr.s_addr=INADDR_ANY;
    bind(sockfd,(struct sockaddr*)&server,sizeof(server));
    bzero((struct sockaddr*)&client ,sizeof(client));
    sendto(sockfd,"hi",sizeof("hi"),0,(struct sockaddr*)&client ,sizeof(client));
    recvfrom(sockfd,ss,sizeof(ss),0,(struct sockaddr*)&client ,&len);
    printf("%s",ss);
    close(sockfd);
}

