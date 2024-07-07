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
    struct sockaddr_in client;
    len=sizeof(client);
    sockfd= socket(AF_INET,SOCK_DGRAM,0);
    bzero((struct sockaddr*)&client ,sizeof(client));
    client.sin_family=AF_INET;
    client.sin_port=htons(2000);
    connect(sockfd,(struct sockaddr*)&client,sizeof(client));
    recvfrom(sockfd,ss,sizeof(ss),0,(struct sockaddr*)NULL,NULL);
    sendto(sockfd,"hello",sizeof("hello"),0,(struct sockaddr*)NULL,sizeof(client));
}