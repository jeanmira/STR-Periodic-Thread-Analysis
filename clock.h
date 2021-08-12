#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <time.h>
#include <signal.h>

#include "tarefa.h"

using namespace std;

#define CLOCKID CLOCK_REALTIME

class Clock
{
private:
    int signo;                     //
    int stat;                      //
    timer_t timerid;               //
    sigset_t signal_set;           //
    struct itimerspec period;      //
    struct itimerspec rest_Period; //
    struct sigaction action;       //

public:
    Clock();                        //
    ~Clock();                       //
    void inicializaTimer(Tarefa T); //
};

#endif