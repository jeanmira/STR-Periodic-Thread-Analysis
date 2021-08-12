#include "clock.h"

Clock::Clock()
{
}

Clock::~Clock()
{
}

void handler(int num)
{
    std::cout << "Deadline perdida!" << endl;
}

void Clock::inicializaTimer(Tarefa T)
{

    sigemptyset(&signal_set);
    sigaddset(&signal_set, SIGALRM);

    action.sa_handler = &handler;
    action.sa_flags = SA_SIGINFO;

    // Criando um timer.
    timer_create(CLOCKID, NULL, &timerid);

    period.it_value.tv_sec = 0;                            //
    period.it_value.tv_nsec = T.getPeriodo() * 1000000;    //
    period.it_interval.tv_sec = 0;                         //
    period.it_interval.tv_nsec = T.getPeriodo() * 1000000; // Período fornecido em mseg, definido em nsec;

    // Setup the timer’s period.
    timer_settime(timerid, 0, &period, NULL);

    while (true)
    {

        sigaction(SIGALRM, &action, NULL);
        sigwait(&signal_set, &signo);

        for (long long int i = 0; i < T.getFatorCarga() * 1000; i++)
        {
            /* Execultando */
        }
        timer_gettime(timerid, &rest_Period);

        std::cout << "Tempo de resposta:" << T.getPeriodo() - (rest_Period.it_value.tv_nsec / 1000000) << "ms" << std::endl;
    }
}