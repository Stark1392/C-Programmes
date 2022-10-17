#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <netinet/in.h>

#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>


typedef struct sockaddr_in SA_IN;
typedef struct sockaddr SA;


long long factorial(n){
    if (n == 0){
        return 1;
    }
    else{
        return(n * factorial(n-1));  
    }
}


int main(){
    //driver code
    int socket_addr, connect_addr, _check, len_addr;
    SA_IN server_addr,client_addr;

    //creating the socket for the server
    socket_addr = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_addr < 0){
        printf("Error in creating socket \n");
    }else{
        printf("Socket created succesful \n");
    }

    memset(&server_addr, 0, sizeof(server_addr));

    // declaring the server info
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(9090);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    //binding the socket
    int bind_check = bind(socket_addr, (SA*)&server_addr, sizeof(server_addr));
    if (bind_check < 0){
        printf("Error in socket \n");
    }else{
        printf("Socket bind succesful \n");
    }

    //listen for client requests
    int listen_check = listen(socket_addr, 10);
    if (_check < 0){
        printf("Error in socket \n");
    }else{
        printf("Socket listening... \n");
    }


    // accept client connection
    len_addr = sizeof(SA_IN);
    connect_addr = accept(socket_addr, (SA*)&client_addr, (socklen_t*)&len_addr);
    if (connect_addr < 0){
        printf("Error in socket \n");
    }else{
        printf("Client connected to socket\n");
        sleep(2);
    }
    

    // handling connect using onConnect function
    long fact_result;
    char buffer[256];
    FILE *fptr;
    fptr = fopen("./newf.txt","w");
    int val = -1;

    while(val <= 20){
        // calulating the factorial
        int buff_size = sizeof(buffer);
        read(connect_addr, buffer, buff_size);
        val = atoi(buffer);
        fact_result = factorial(val);
        if(val > 20){
            //debugging, remove before submission
            break;
        }

        // writing to the file
        fprintf(fptr,"%li",fact_result);

        // sending response from the server
        char str[256];
        sprintf(str, "%ld", fact_result);
        write(connect_addr, str, sizeof(str));
    }

    fclose(fptr);

    //close connection
    printf("Closing socket...\n");
    sleep(1);
    close(socket_addr);
}
