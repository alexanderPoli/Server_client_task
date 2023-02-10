#include <iostream>
#include <string>
#include <semaphore.h>
#include <locale>
#include "../Exceptions/exception.h"
#include "../common/constants.h"
#include "../common/functions.h"

extern int proccesing_file(std::string protocol_file, std::string file_name);

int main(int argc, char *argv[])
{
    try
    {
        if (argc == 1)
        {
            throw InvalidParametrEcxeption("incorrect count parametrs");
        }
        extern sem_t *sem;
        sem = sem_open(SEMAPHORE_NAME, 0);

        proccesing_file(std::string(argv[1]), std::string(argv[2]));

        sem_destroy(sem);
    }
    catch (const std::exception &e)
    {
        save_protocol_error(std::string(argv[1]), e.what());
    }

    return 0;
}
