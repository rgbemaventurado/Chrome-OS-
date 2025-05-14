#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define PORT 8080 // Port number to bind the socket
int main() {
 int sockfd;
 struct sockaddr_in server_addr;
 // Step 1: Create a socket
 sockfd = socket(AF_INET, SOCK_STREAM, 0);
 if (sockfd == -1) {
 perror("Socket creation failed");
 exit(EXIT_FAILURE);
 }
 // Step 2: Set up the server address structure
 memset(&server_addr, 0, sizeof(server_addr));
 server_addr.sin_family = AF_INET; // Address
family
 server_addr.sin_addr.s_addr = INADDR_ANY; // Any available
network interface
 server_addr.sin_port = htons(PORT); // Port to bind
(converted to network byte order)
 // Step 3: Bind the socket to the specified address and port
 if (bind(sockfd, (struct sockaddr*)&server_addr,
sizeof(server_addr)) == -1) {
 perror("Bind failed");
 close(sockfd);
Page | 4
 exit(EXIT_FAILURE);
 }
 printf("Socket successfully bound to port %d\n", PORT);
 // Additional steps can be added here, like listening for
connections
 // Close the socket
 close(sockfd);
 return 0;
}
