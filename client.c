#include<stdio.h>
#include<stdlib.h>

#include<winsock.h>
#pragma comment(lib, "Ws2_32.lib")

int main()
{
    int csocket = socket(AF_INET, SOCK_STREAM, 0);

    //specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addrs_addr = INADDR_ANY;


    int connection_status = connect(csocket, (struct sockaddr*)&server_address, sizeof(server_address));

    if (connection_status == -1)
    {
        printf("error in connection");
    }

    char server_res[256];
    recv(csocket, &server_res, sizeof(server_res), 0);

    //print out the server response
    printf("%s", server_res);

    close(csocket);
    return 0;
}
