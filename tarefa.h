#ifndef TAREFA_H
#define TAREFA_H

#include <iostream>

using namespace std;

class Tarefa
{
private:
    int periodo;                  // Período (em milisegundos, de 1 ms a 999 ms)
    int prioridade;               // Prioridade da tarefa/thread
    int fatorCarga;               // fator de carga da CPU
    string polıticaEscalonamento; // Política de escalonamento (SCHED_FIFO ou SCHED_RR)

public:
    Tarefa(int per, int pri, int fat, string pol); // Construtor padrão

    void setPeriodo(int per);                  //
    void setPrioridade(int pri);               //
    void setFatorCarga(int fat);               //
    void setPolıticaEscalonamento(string pol); //

    int getPeriodo();                  //
    int getPrioridade();               //
    int getFatorCarga();               //
    string getPolıticaEscalonamento(); //

    void cargaGenerica(int carga);
};

#endif