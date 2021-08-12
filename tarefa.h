#ifndef TAREFA_H
#define TAREFA_H

#include <iostream>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sched.h>

using namespace std;

class Tarefa
{
private:
    int periodo;                                         // Período (em milisegundos, de 1 ms a 999 ms)
    int prioridade;                                      // Prioridade da tarefa/thread
    int fatorCarga;                                      // fator de carga da CPU
    string politicaEscalonamento;                        // Política de escalonamento (SCHED_FIFO ou SCHED_RR)
    struct sched_param politica = {.sched_priority = 2}; //

public:
    Tarefa();
    ~Tarefa(); //

    void setPeriodo(int per);                  //
    void setPrioridade(int pri);               //
    void setFatorCarga(int fat);               //
    void setPoliticaEscalonamento(string pol); //

    int getPeriodo();                  //
    int getPrioridade();               //
    int getFatorCarga();               //
    string getPoliticaEscalonamento(); //

    void cargaGenerica(int laod); //
    void escalonamento();         //
};

#endif