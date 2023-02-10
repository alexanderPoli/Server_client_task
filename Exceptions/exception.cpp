#include "exception.h"

InvalidParametrEcxeption::InvalidParametrEcxeption(std::string str)
{
    this->error_parametr = "Invalid Parametr Ecxeption:" + str;
}

const char *InvalidParametrEcxeption::what() const throw()
{
    return error_parametr.c_str();
}

InvalidRecordEcxeption::InvalidRecordEcxeption(std::string str)
{
    this->error_parametr = "Invalid Record Ecxeption:" + str;
}

const char *InvalidRecordEcxeption::what() const throw()
{
    return error_parametr.c_str();
}

SoketConnectEcxeption::SoketConnectEcxeption(std::string str)
{
    this->error_parametr = "Problem with connection:" + str;
}

const char *SoketConnectEcxeption::what() const throw()
{
    return error_parametr.c_str();
}
