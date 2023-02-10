#include <iostream>
#include <string>
#include <semaphore.h>
#include <fcntl.h>
#include "../Exceptions/exception.h"
#include "../common/constants.h"
#include "../common/functions.h"

extern int server_(std::string file_path);

int main(int argc, char *argv[])
{
    while (true)
    {
        try
        {
            if (argc == 1)
            {
                throw InvalidParametrEcxeption("incorrect count parametrs");
            }

            extern sem_t *sem;
            sem = sem_open(SEMAPHORE_NAME, O_CREAT, 0777, 1);

            server_(std::string(argv[1]));

            sem_destroy(sem);
        }
        catch (const std::exception &e)
        {
            save_protocol_error(std::string(argv[1]), e.what());
            std::cout << e.what() << '\n';
        }
    }

    return 0;
}
