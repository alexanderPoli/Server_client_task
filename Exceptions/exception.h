#include <string>

class InvalidParametrEcxeption : public std::exception
{
    int error_code = 0x1;
    std::string error_parametr;

public:
    InvalidParametrEcxeption(std::string str);
    const char *what() const throw();
};

class InvalidRecordEcxeption : public std::exception
{
    int error_code = 0x2;
    std::string error_parametr;

public:
    InvalidRecordEcxeption(std::string str);
    const char *what() const throw();
};

class SoketConnectEcxeption : public std::exception
{
    int error_code = 0x3;
    std::string error_parametr;

public:
    SoketConnectEcxeption(std::string str);
    const char *what() const throw();
};