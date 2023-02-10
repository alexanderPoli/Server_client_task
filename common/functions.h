#include <vector>
#include <string>
#include "../common/record.h"

Record get_object(std::string line, const std::string &separator, std::vector<std::string> &substrings);

void save_server_data(const std::string &protocol_file, const std::string &source_file, const Record obj);

void save_client_data(const std::string &protocol_file, const std::string &source_file, const std::string &count_str);

void save_protocol_error(const std::string &protocol_file, const std::string &data);