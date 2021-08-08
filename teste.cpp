
#include <iostream>
#include <time.h>
#include <signal.h>

#define periodo 999

#define CLOCKID CLOCK_REALTIME

timer_t timerid;     //
sigset_t signal_set; //
struct itimerspec timer_spec;
/**************************************************************/
int main()
{
    // Create a timer.
    timer_create(CLOCKID, NULL, &timerid);

    // Specify the timer’s period.
    timer_spec.it_value.tv_sec = 0;
    timer_spec.it_value.tv_nsec = 1; /* Start immediately */
    timer_spec.it_interval.tv_sec = 0;
    timer_spec.it_interval.tv_nsec = periodo * 1000000; // period given in msec, set in nsec;

    // Setup a signal set for sigwait() to wait for SIGALRM
    sigemptyset(&signal_set);
    sigaddset(&signal_set, SIGALRM);

    // Don't block t
    // Don't block the signal in signal_set to use the catcher in case of a
    // deadline miss sigprocmask(SIG_BLOCK, &signal_set, NULL);
    std::cout << "Periodic timer set with period = " << periodo << "msec." << std::endl;

    // Setup the timer’s period.
    timer_settime(timerid, 0, &timer_spec, NULL);

    for (long long int i = 0; i < 100000000 * 1000; i++)
    {
        /* Execultando */
    }
    
    timer_gettime(timerid, &timer_spec);
}