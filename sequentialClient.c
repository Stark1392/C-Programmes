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


int main(){
    //driver code
    int socket_addr, connect_addr, len_addr;
    SA_IN server_addr, client_addr;
    int response;

    //creating the socket
    socket_addr = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_addr < 0){
        printf("Error in socket \n");
    }else{
        printf("Socket created \n");
        sleep(1);
    }

    memset(&server_addr,0 ,sizeof(server_addr));

    // declaring the server info
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(9090);

    //connecting the socket for sending requests
    int connect_check = connect(socket_addr, (SA*)&server_addr, sizeof(server_addr));
    if (connect_check < 0){
        printf("Error in socket \n");
    }else{
        printf("Socket connection succesful \n");
    }

    // handling connect using onConnect function
    int i;
    // sending 20 requests
    for(i=1; i <= 20; i++){
        char response[256];
        char str[256];
        sprintf(str, "%d", i);

        write(socket_addr, str, sizeof(str));
        read(socket_addr, &response, sizeof(response));
        printf("Request num: %d Response from rom Server : %s \n", i, response);
    }

    //close connection
    close(socket_addr);

    return 0;
}
