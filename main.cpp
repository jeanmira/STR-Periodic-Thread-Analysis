//  • 1.º Passo - Ler o manual das duas bibliotecas (Tratamento do alarme com o sigwait), para detectar perda de deadline;
//  • 2.º Passo - Implementar thread periódica;
//  • 3.º Passo - Colocar o fator de carga na thread;
//  • 4.º Passo - Alterar a política de escalonamento na thread;
//  • 5.º Passo - Rodar os dois programas em paralelo e fazer analise.

#include "escalonamento.h"
#include "tarefa.h"
#include "clock.h"

#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{

    std::vector<Tarefa> tarefas;
    Tarefa tarefa1("t1", 500, 100000);
    Tarefa tarefa2("t2", 500, 100000);
    tarefas.push_back(tarefa2);
    tarefas.push_back(tarefa2);

    return 0;
}
