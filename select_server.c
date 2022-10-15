#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#define MAX 80
#define PORT 8789
#define SA struct sockaddr
#define DATA_BUFFER 5000
#define MAX_CONNECTIONS 10 


// Function to calculate factorial
long factorial(long n)
{
	if (n == 0)  
    	return 1;  
  	else  
    	return(n * factorial(n-1)); 
}

// Driver function
int main()
{

	int sockfd, connfd, len, ret_val, fp;
	fd_set read_fd_set;
	struct sockaddr_in servaddr, cli;
	char buffer[250];
	len = sizeof(struct sockaddr_in);
	char buf[DATA_BUFFER];
    int all_connections[MAX_CONNECTIONS];

	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
		printf("socket bind failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully binded..\n");
	// Now server is ready to listen and verification
	if ((listen(sockfd, 10)) != 0) {
		printf("Listen failed...\n");
		exit(0);
	}
	else
		printf("Server listening..\n");
	
	for (int i=0;i < MAX_CONNECTIONS;i++) {
			all_connections[i] = -1;
		}
	all_connections[0] = sockfd;


	while(1)
	{
																																							fork();
		FD_ZERO(&read_fd_set);
        /* Set the fd_set before passing it to the select call */																						
        for (int i=0;i < MAX_CONNECTIONS;i++) {
            if (all_connections[i] >= 0) {
                FD_SET(all_connections[i], &read_fd_set);
            }
        }

		/* Invoke select() and then wait! */
        // printf("\nUsing select() to listen for incoming events\n");
        ret_val = select(FD_SETSIZE, &read_fd_set, NULL, NULL, NULL);

		if (ret_val >= 0 ) {
            printf("Select returned with %d\n", ret_val);
            /* Check if the fd with event is the server fd */
            if (FD_ISSET(sockfd, &read_fd_set)) { 
                /* accept the new connection */
                printf("Returned fd is %d (server's fd)\n", sockfd);
                connfd = accept(sockfd, (SA*)&cli, (socklen_t*)&len);
                if (connfd >= 0) {
                    printf("Accepted a new connection with fd: %d\n", connfd);
                    for (int i=0;i < MAX_CONNECTIONS;i++) {
                        if (all_connections[i] < 0) {
                            all_connections[i] = connfd; 
                            break;
                        }
                    }
                } else {
                    fprintf(stderr, "accept failed [%s]\n", strerror(errno));
                }
                ret_val--;
                if (!ret_val) continue;
            } 

            /* Check if the fd with event is a non-server fd */
            for (int i=1;i < MAX_CONNECTIONS;i++) {
                if ((all_connections[i] > 0) &&
                    (FD_ISSET(all_connections[i], &read_fd_set))) {
                    /* read incoming data */   
                    printf("Returned fd is %d [index, i: %d]\n", all_connections[i], i);
                    // ret_val = recv(all_connections[i], buf, DATA_BUFFER, 0);
					fp = open("out.txt", O_WRONLY | O_APPEND);
					for(int j = 1; j < 21; j++)
					{
						bzero(buffer, 250);
						printf("Receiving data from client\n");
						sleep(1);
						recv(connfd, &buffer, 250, 0);
						printf("from client: %s\n", buffer);
						long input = atoi(buffer);
						long num = factorial(input);
						printf("Calculating factorial now...\n");
						sleep(1);
						bzero(buffer, 250);
						char string[20];
						sprintf(string, "%ld", num);
						strcpy(buffer, string);
						printf("Sending data to client\n");
						send(connfd, &buffer, 250, 0);
						int data_length = snprintf(NULL, 0, "PORT: %d, IP: %s, factorial: %ld\n", (int) ntohs(cli.sin_port), inet_ntoa(cli.sin_addr), num);
						char *output = malloc(data_length + 1);
						snprintf(output, data_length + 1, "PORT: %d, IP: %s, factorial: %ld\n", (int) ntohs(cli.sin_port), inet_ntoa(cli.sin_addr), num);
						write(fp, output, strlen(output));
						free(output);
					}
					close(fp);
                    close(all_connections[i]);
                    all_connections[i] = -1; /* Connection is now closed */
                }
                ret_val--;
                if (!ret_val) continue;
            } /* for-loop */
        }
		
	}
	for (int i=0;i < MAX_CONNECTIONS;i++) {
        if (all_connections[i] > 0) {
            close(all_connections[i]);
        }
    }

	// After chatting close the socket
	sleep(1);
	printf("Server now closing.....\n");
	
	close(sockfd);
	// fclose(fp);
}
