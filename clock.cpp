#include "clock.h"

Clock::Clock()
{
}

void Clock::inicializaTimer(long periodo)
{
    struct itimerspec timer_spec;

    // Crie um cronômetro.
    if (timer_create(CLOCKID, NULL, &timerid) == -1)
        errExit("timer_create");

    // Especifique o período do cronômetro.
    timer_spec.it_value.tv_sec = 0;
    timer_spec.it_value.tv_nsec = 1; // Comece imediatamente
    timer_spec.it_interval.tv_sec = 0;
    timer_spec.it_interval.tv_nsec = periodo * 1000000; // Período fornecido em mseg, definido em nsec;

    // Configure um sinal definido para sigwait () para esperar por SIGALRM
    sigemptyset(&signal_set);
    sigaddset(&signal_set, SIGALRM);

    // Configure o período do cronômetro.
    if (timer_settime(timerid, 0, &timer_spec, NULL) == -1)
        errExit("timer_settime");

    printf("Periodic timer set with period = %ldmsec.\n", periodo);
}