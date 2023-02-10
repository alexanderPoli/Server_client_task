#define TIME_TEMPLATE "%d.%m.%Y %H:%M:%S"


constexpr int MAX_BUFFER_SIZE = 100;
constexpr int SOCK_PORT= 3425;
constexpr int SIZE_CONNECT_QUEUE = 10;

const std::string SEPARATORS = ";";
constexpr int COUNT_ROW = 3;

constexpr int MAX_ACK_SIZE= 4;
const std::string ACK_ANS = "OK";
const std::string END_CONNECTION_MES = "END";

#define SEMAPHORE_NAME "/my_named_semaphore"