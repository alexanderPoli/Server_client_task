#include <time.h>
#include <stdio.h>
#include <string>
#include "record.h"
#include "../Exceptions/exception.h"
#include "constants.h"

Record::Record()
{
    time = 0;
    first = 0.0;
    second = 0.0;
}

Record::Record(time_t time, double first, double second)
{
    this->time = time;
    this->first = first;
    this->second = second;
}

time_t Record::get_time() const
{
    return time;
}

std::string Record::get_time_str() const
{
    constexpr int max_buffer_size = 20; // «dd.mm.yyyy hh:mm:ss»
    char buffer[max_buffer_size];
    if (!strftime(buffer, sizeof(buffer), TIME_TEMPLATE, gmtime(&time)))
    {
        printf("Error code:");
    }
    return std::string(buffer);
}

std::string Record::get_quotient_str() const
{
    if (second == 0)
    {
        throw InvalidRecordEcxeption("Divade by zero. " + get_str());
    }
    return std::to_string(first / second);
}

std::string Record::get_str() const
{
    return get_time_str()+";"+ std::to_string(first) +";"+ std::to_string(second) +";";
}