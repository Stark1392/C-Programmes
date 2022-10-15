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
#define MAX 250
#define PORT 8081
#define SA struct sockaddr


// Function to calculate factorial
long factorial(long n)
{
	if (n == 0)  
    	return 1;  
  	else  
    	return(n * factorial(n-1)); 
}

int main()
{
	
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;

	char buffer[250];

	socklen_t addr_size; // Stores byte size of server socket address

	pid_t childpid; 
	len = sizeof(struct sockaddr_in);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");
	
	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);

	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
		printf("socket bind failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully binded..\n");

	if ((listen(sockfd, 10)) != 0) {
		printf("Listen failed...\n");
		exit(0);
	}
	else
		printf("Server listening..\n");
	int cnt = 0;
	while(1)
	{
																																										fork();fork();fork();fork();
		int fp = open("out.txt", O_WRONLY | O_APPEND);
		if(fp < 0)
		{
			perror("File already created..\n");
			exit(1);
		}

		connfd = accept(sockfd, (SA*)&cli, (socklen_t*)&len);
		if (connfd < 0) {
			printf("server accept failed...\n");
			exit(0);
		}
		else
			printf("server accept the client...\n");


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
		close(connfd);

	}

	// After chatting close the socket
	sleep(1);
	printf("Server now closing.....\n");
	
	close(sockfd);
}
