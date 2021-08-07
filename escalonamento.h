#ifndef FCFS_H
#define FCFS_H

#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <unistd.h>

#include "tarefa.h"

class Escalonamento
{
private:
    vector<Tarefa> tarefas; // Vetor de processos

public:
    Escalonamento();                         // Construtor padrão
    ~Escalonamento();                        // Destrutor padrão
    void setParametros(Tarefa novasTarefas); // Cria os objetos e adiciona os parâmetros
    bool verificaPreEmpetivo();              // Verifica se é preemptivo
    void imprimiDados();                     // Imprime os dados dos processos
    void fcfs();                             // Escalonamento por FCFS (First Come, First Served)
    void rrsp(int quantum);                  // Escalonamento por Round-Robin com quantum = 2s, sem prioridade
};

#endif
