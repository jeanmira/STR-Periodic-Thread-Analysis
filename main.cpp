#include "clock.h"
#include "tarefa.h"

int main()
{
    Tarefa T;
    T.escalonamento();

    Clock C;
    C.inicializaTimer(T);

    return 0;
}