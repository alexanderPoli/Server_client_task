#include <string>
#include <fstream>
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include "../Exceptions/exception.h"
#include "functions.h"

sem_t *sem;
void save_protocol_data(const std::string &protocol_file, const std::string &data)
{
    std::ofstream out(protocol_file, std::ios::app);
    if (out.is_open())
    {
        sem_wait(sem);
        out << data << std::endl;
        sem_post(sem);
        out.close();
    }
    else
    {
        throw InvalidParametrEcxeption("Problem with save data. File [" + protocol_file + 
        "] can\'t be open. " + "data [" + data + "];");
    }
}

void save_server_data(const std::string &protocol_file, const std::string &source_file, const Record obj)
{
    std::string data = "Server from " + source_file + " :" + obj.get_time_str() + " | " + obj.get_quotient_str() + " ;";
    save_protocol_data(protocol_file, data);
}

void save_client_data(const std::string &protocol_file, const std::string &source_file, const std::string &count_str)
{
    std::string data = "Client " + source_file + ": " + count_str + " ;";
    save_protocol_data(protocol_file, data);
}

void save_protocol_error(const std::string &protocol_file, const std::string &data)
{
    save_protocol_data(protocol_file, data);
}