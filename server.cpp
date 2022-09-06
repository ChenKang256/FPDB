#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <iostream>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>

#define PORT 4242
#define IP "192.168.1.4"

using namespace std;
 
int main()
{
    int sockfd = -1;
    int bindres = -1;
    int listenres = -1;
 
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(-1 == sockfd){
        perror("sock created");
        exit(-1);
    }
 
    struct sockaddr_in server;
    memset(&server,0,sizeof(struct sockaddr_in));
    server.sin_addr.s_addr = inet_addr(IP);
    server.sin_port = htons(PORT);
    server.sin_family = AF_INET;
 
    bindres = bind(sockfd,(struct sockaddr*)&server,sizeof(server));
 
    if(-1 == bindres){
        perror("sock bind");
        exit(-1);
    }
 
    listenres = listen(sockfd,10);
    if(-1 == listenres){
        perror("sock listen");
        exit(-1);
    }
 
    struct sockaddr_in peerServer;
    int acceptfd = -1;
    socklen_t len = sizeof(peerServer);
    acceptfd = accept(sockfd,(struct sockaddr *)&peerServer,&len);
    if(-1 == acceptfd){
        perror("sock accept");
        exit(-1);
    }
 
    char recvBuf[1024];
    long long totalSize = 0;
    while (1) {
        memset(recvBuf, 0, sizeof(recvBuf));
        int recvRes = recv(acceptfd,recvBuf,sizeof(recvBuf),0);
        if (recvRes == 0) {
            break;
        }
        totalSize += sizeof(recvBuf);
    }
    cout << "Total char count: " + to_string(totalSize) << endl;
    close(acceptfd);
    close(sockfd);
 
    return 0;
}