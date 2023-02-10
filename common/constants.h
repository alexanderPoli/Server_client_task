// parameters for parsing file
#define TIME_TEMPLATE "%d.%m.%Y %H:%M:%S"
const std::string SEPARATORS = ";";
constexpr int COUNT_ROW = 3;

// parameters for configure connection
constexpr int SOCK_PORT = 3425;
constexpr int SIZE_CONNECT_QUEUE = 10;

// info for work connection
constexpr int MAX_BUFFER_SIZE = 100;
constexpr int MAX_ACK_SIZE = 4;
const std::string ACK_ANS = "OK";
const std::string END_CONNECTION_MES = "END";

#define SEMAPHORE_NAME "/server_client_semaphore"