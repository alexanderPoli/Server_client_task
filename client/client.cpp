#include <netinet/in.h>
#include <unistd.h>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include "../common/constants.h"
#include "../Exceptions/exception.h"
#include "../common/functions.h"


void send_with_ack(int socket, const std::string &data)
{
    char ack_buff[MAX_ACK_SIZE];
    send(socket, data.c_str(), data.size(), 0);
    int count = recv(socket, ack_buff, MAX_ACK_SIZE, 0);
    if(count<=0 || std::string(ack_buff) != ACK_ANS)
    {
         throw SoketConnectEcxeption("Client problem. Wrong ACK. Soket:" + std::to_string(socket));
    }
}

int send_data(std::string protocol_file, std::string source_file, const std::vector<std::string>& data)
{
    int sock;
    struct sockaddr_in addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        throw SoketConnectEcxeption("Client problem. Cannot create soket:" + std::to_string(sock));
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(SOCK_PORT);
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        throw SoketConnectEcxeption("Client problem. Cannot connect soket:" + std::to_string(sock));
    }
    send_with_ack(sock, source_file);

    for(auto &mes :data)
    {
        send_with_ack(sock, mes);
    }
    send_with_ack(sock, END_CONNECTION_MES);

    char buf[MAX_BUFFER_SIZE];
    memset(buf, 0, MAX_BUFFER_SIZE);
    recv(sock, buf, MAX_BUFFER_SIZE, 0);

    std::string count_str  = std::string(buf);
    save_client_data(protocol_file,source_file, count_str);

    close(sock);

    return 0;
}