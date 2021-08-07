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

    int per = 0, pri = 0, fat = 0;
    string pol;

    cin >> per;
    if (per != -1)
    {
        cin >> pri;
        cin >> fat;
        cin >> pol;
        Tarefa tarefa1(per, pri, fat, pol);
    }
    else
    {
        Tarefa tarefa1(500, 1, 100000, "SCHED_RR");
        Tarefa tarefa2(500, 1, 100000, "SCHED_RR");
        vector<Tarefa> tarefas{tarefa1, tarefa2};
        Clock cronometro();
    }

    return 0;
}
