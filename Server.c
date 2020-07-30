#include<stdio.h>
#include<stdlib.h>
#include<winsock.h>
#pragma comment(lib, "Ws2_32.lib")



int main()
{
    // Initialise the WSA function
    WSADATA ws;
    if (WSAStartup (MAKEWORD(2,2),&ws) < 0)
    {
        printf("wsa failed \n");
    }
    else
    {
        printf("WSA initialised\n");
    }


    char server_msg[256] = "you are good";

    int s_socket;
    s_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (s_socket < 0)
    {
        printf("The socket not opened\n");
    }
    else
    {
        printf("The socket is opened\n");
        printf("%d \n", s_socket);
    }
    // Initialize the environment for sockaddr structure
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY; //IP address of my machine
    //server_address.sin_addr.s_addr = inet_addr("127.02.739"); convert ip addr in byte order
    memset(&(server_address.sin_zero), 0, 8);


    //Bind the socket to the local port
    
    bind(s_socket, (struct sockaddr*)&server_address, sizeof(server_address));

    if (bind < 0)
    {
        printf("Fail to bind\n");
    }
    else
    {
        printf("bind successfully \n");
    }
    
    //listen the request from client (queue the request)
    listen(s_socket, 3);

    if (listen < 0)
    {
        printf("Fail to listen \n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("started listen \n");
    }
   
    int csocket;
    //accept(socketWeAreAccepting,structuresClientIsConnectingFrom,)
    csocket = accept(s_socket, NULL, NULL);

    //sending data
    //send(toWhom,Message,SizeOfMessage,FLAG);
    send(csocket ,server_msg, sizeof(server_msg), 0);

    //close the socket
    close(s_socket);
    return 0;

}

