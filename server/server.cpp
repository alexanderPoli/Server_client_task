#include <iostream>
#include <string>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <thread>
#include "../common/constants.h"
#include "../Exceptions/exception.h"
#include "../common/functions.h"

std::string recv_with_ack(int socket, char *buf)
{
    memset(buf, 0, MAX_BUFFER_SIZE);
    int count = recv(socket, buf, MAX_BUFFER_SIZE, 0);
    send(socket, ACK_ANS.c_str(), ACK_ANS.size(), 0);
    if (count <= 0 || std::string(buf) == END_CONNECTION_MES)
    {
        return "";
    }
    return std::string(buf);
}

void proccesing_data(int socket, std::string file_path)
{
    std::vector<std::string> substrings;
    substrings.reserve(COUNT_ROW);
    Record record_max;
    int counter_records = 0;
    std::string file_name;
    try
    {
        char buf[MAX_BUFFER_SIZE];
        file_name = recv_with_ack(socket, buf);

        while (true)
        {
            std::string mes = recv_with_ack(socket, buf);
            if (mes.empty())
            {
                break;
            }
            Record temp = get_object(mes, SEPARATORS, substrings);

            counter_records++;
            if (temp.get_time() > record_max.get_time())
            {
                record_max = temp;
            }
        }

        std::string request = std::to_string(counter_records);
        send(socket, request.c_str(), request.size(), 0);

        close(socket);

        save_server_data(file_path, file_name, record_max);
    }
    catch (const std::exception &e)
    {
        save_protocol_error(file_path, "Problem with proccesing file:" + file_name);
        std::cout << "Problem with proccesing file:" << file_name << std::endl;
        std::cout << e.what() << '\n';
    }
}

int server_(std::string file_path)
{
    int sock, listener;
    struct sockaddr_in addr;

    listener = socket(AF_INET, SOCK_STREAM, 0);
    if (listener < 0)
    {
        throw SoketConnectEcxeption("Server problem. Cannot create soket for listen.");
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(SOCK_PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        throw SoketConnectEcxeption("Server problem. Issue with bind.");
    }

    listen(listener, SIZE_CONNECT_QUEUE);

    while (true)
    {
        sock = accept(listener, NULL, NULL);
        if (sock < 0)
        {
            throw SoketConnectEcxeption("Server problem. Issue with accept connection.");
        }
        std::thread th(proccesing_data, sock, file_path);
        th.detach();
    }

    return 0;
}