#include <string.h>
#include <iostream>
#include <sstream>
#include <iomanip>

#include "../Exceptions/exception.h"
#include "functions.h"
#include "constants.h"

long int time_cost(const std::string time)
{
    struct tm tm;
    memset(&tm, 0, sizeof(tm));

    std::istringstream ss(time);
    ss >> std::get_time(&tm, TIME_TEMPLATE);
    return mktime(&tm);
}

void get_substing(std::string line, const std::string &separator, std::vector<std::string> &substrings)
{
    substrings.clear();
    std::size_t start_pos = 0;
    std::size_t pos = 0;

    std::size_t sep_length = separator.size();
    while ((pos = line.find(separator, start_pos)) && pos != std::string::npos)
    {
        substrings.push_back(line.substr(start_pos, pos - start_pos));
        start_pos = pos + sep_length;
    }
}

Record get_object(std::string line, const std::string &separator, std::vector<std::string> &substrings)
{
    get_substing(line, separator, substrings);
    return Record(time_cost(substrings[0]), std::stod(substrings[1]), std::stod(substrings[2]));
}