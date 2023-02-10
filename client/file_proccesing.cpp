#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "../Exceptions/exception.h"


void fix_string_for_format(std::string& line)
{
    int end = line.size() - 1 ;
    while(line[end] == ' ')
    {
        line.pop_back();
    }
    if(line[end]!= ';')
    {
        line.push_back(';');
    }
}


void read_file(std::ifstream &in, std::vector<std::string>& files_records)
{
    const std::string separators = ";";
    constexpr int COUNT_ROW = 3;
    std::vector<std::string> substrings;
    substrings.reserve(COUNT_ROW);

    std::string line;
    while (getline(in, line))
    {
        if(line.empty())
        {
            continue;
        }
        fix_string_for_format(line);
        files_records.push_back(line);
    }

}

extern int send_data(std::string protocol_file, std::string source_file, const std::vector<std::string>& data);

int proccesing_file(std::string protocol_file, std::string file_name)
{
    std::vector<std::string> files_records;
    std::ifstream in(file_name); 
    if (in.is_open())
    {
        read_file(in, files_records);
        in.close();
    }
    else
    {
        throw InvalidParametrEcxeption("File [" + file_name + "] can\'t be open");
    }
    send_data(protocol_file, file_name, files_records);

    return 0;
}

