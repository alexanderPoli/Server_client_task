#include <string>

class Record
{
    time_t time;
    double first;
    double second;

public:
    Record();
    Record(time_t, double, double);
    time_t get_time() const;
    std::string get_time_str() const;
    std::string get_quotient_str() const;
    std::string get_str() const;
};