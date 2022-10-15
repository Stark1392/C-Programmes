#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <stdbool.h>
#include <limits.h>
#include <poll.h>
#include <fcntl.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr


// Function to calculate factorial
int factorial(int n)
{
	if (n == 0)  
    	return 1;  
  	else  
    	return(n * factorial(n-1)); 
}

// Driver function
int main()
{
	
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;
	char buffer[250];
    int nfds = 1, current_size = 0;
    struct pollfd fds[10];
    int timeout, rc;

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

    memset(fds, 0, sizeof(fds)); 

    fds[0].fd = sockfd;
    fds[0].events = POLLIN;

    timeout = (3 * 60 * 1000);

    while(1)
    {
                                                                                                                                                                                fork();
        int fp = open("out.txt", O_WRONLY | O_APPEND);
        printf("Waiting of poll...\n");
        rc = poll(fds, nfds, timeout);
        if(rc == 0)
        {
            printf("Poll() timed out. End program.\n");
            break;
        }
        if(rc < 0)
        {
            printf("Error on poll..\n");
            break;
        }
        

        current_size = nfds;
        for(int i = 0; i < current_size; i++)
        {
            if(fds[i].revents == 0)
            {
                continue;
            }
            if(fds[i].revents != POLLIN)
            {
                printf("  Error! revents\n");
                // end_server = TRUE;
                break;

            }
            if(fds[i].fd == sockfd)
            {
                printf("Listening socket is readable\n");
                len = sizeof(struct sockaddr_in);
                connfd = accept(sockfd, (SA*)&cli, (socklen_t*)&len);
                if (connfd < 0) {
                    printf("server accept failed...\n");
                    exit(0);
                }
                else
                    printf("server accept the client...\n");
                printf("New incoming connection\n");
                fds[nfds].fd = connfd;
                fds[nfds].events = POLLIN;
                nfds++;
            }
            else
            {
                printf("Descriptor is readable\n");
                printf("Opening the data.txt\n");
		        sleep(1);
		        
                for(int i = 1; i < 21; i++)
                {
                    bzero(buffer, 250);
                    printf("Receiving data from client:\n");
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

            }
        }
    }

	// After chatting close the socket
	sleep(1);
	printf("Server now closing.....\n");	
	close(sockfd);
    return EXIT_SUCCESS;
}
