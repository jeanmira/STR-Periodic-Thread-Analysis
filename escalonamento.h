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
    void selecionaEscalonamento();           // Seleciona um dos dois escalonadores
    void fcfs();                             // Escalonamento por FCFS (First Come, First Served)
    void rrsp();                             // Escalonamento por Round-Robin com prioridade
};

#endif
