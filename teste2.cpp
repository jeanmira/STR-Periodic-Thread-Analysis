#include <iostream>
#include <unistd.h>
#include <sched.h>

int main()
{

    struct sched_param sp = {.sched_priority = 2};

    int ret;
    int politica;
    ret = sched_setscheduler(getpid(), SCHED_RR, &sp);

    if (ret == -1)
    {
        perror("ERRO");
        return 1;
    }

    politica = sched_getscheduler(getpid());

    switch (politica)
    {
    case SCHED_RR:
        std::cout << "SCHED_RR" << std::endl;
        break;
    case SCHED_FIFO:
        std::cout << "SCHED_FIFO" << std::endl;
        break;
    case SCHED_OTHER:
        std::cout << "SCHED_OTHER" << std::endl;
        break;
    }
}
