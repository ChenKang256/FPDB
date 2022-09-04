#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
 
#define PORT 4242
#define IP "192.168.1.4"

using namespace std;

int main()
{
    int sockfd = -1;
 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == sockfd) {
        perror( "sock created" );
        exit( -1 );
    }
 
    struct sockaddr_in server;
    memset(&server, 0, sizeof(struct sockaddr_in));
    server.sin_addr.s_addr = inet_addr(IP);
    server.sin_port = htons(PORT);
    server.sin_family = AF_INET;
 
    int res = -1;
    res = connect(sockfd, (struct sockaddr*)&server, sizeof(server) );
    if(-1 == res){
        perror( "sock connect" );
        exit( -1 );
    }
 
    char sendBuf[1024] = {0};
    FILE* f = fopen("/home/partho/Work/FPDB-build/resources/metadata/ssb-sf10-sortlineorder/csv/data/lineorder_sharded/lineorder.tbl.0", "r");
    while(fgets(sendBuf, sizeof(sendBuf), f) != NULL) {
        send(sockfd, sendBuf, sizeof(sendBuf), 0);
        memset(sendBuf, 0, sizeof(sendBuf));
        cout << "Successful send a message!" << endl;
    }
    close(sockfd);
    fclose(f);
    return 0;
}
