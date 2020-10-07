#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
extern int h_errno;

void bzero(void *s, size_t n);
//struct hostent *gethostbyname(const char *name);
int main(int argc, char **argv){
char *hostName = argv[1];
char c;
struct sockaddr_in serverAddress;
struct hostent *serverInfo = gethostbyname(hostName);
bzero(&serverAddress, sizeof(serverAddress));
//printf("official name %s, ipaddres \n", hostInfo->h_name);
//for (int i = 0; i<hostInfo->h_length; i++) {
//printf("%d", hostInfo->h_addr[i]);
//}
serverAddress.sin_family = AF_INET;
serverAddress.sin_port = htons(80);
// serverAddress.sin_addr = serverInfo->h_addr_list[0]; no se 
bcopy((char *)serverInfo->h_addr,
    (char *)&serverAddress.sin_addr.s_addr, serverInfo->h_length);
int sockfd = socket(AF_INET, SOCK_STREAM, 0);
connect(sockfd, &serverAddress, sizeof(serverAddress));
    


char *message = "GET / HTTP/1.0\r\n\r\n";
write(sockfd,message,strlen(message));
while (read(sockfd,&c,1)) {
printf("%c", c);
}
printf("\n");
return 0;

}