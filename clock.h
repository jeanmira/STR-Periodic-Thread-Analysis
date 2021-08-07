#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <time.h>
#include <signal.h>

using namespace std;

#define CLOCKID CLOCK_REALTIME
#define SIG SIGRTMIN

#define errExit(msg)        \
    do                      \
    {                       \
        perror(msg);        \
        exit(EXIT_FAILURE); \
    } while (0)

class Clock
{
private:
    timer_t timerid;     //
    sigset_t signal_set; //

public:
    Clock();
    void inicializaTimer(long periodo);
};

#endif