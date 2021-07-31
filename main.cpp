//  • 1.º Passo - Ler o manual das duas bibliotecas (Tratamento do alarme com o sigwait), para detectar perda de deadline;
//  • 2.º Passo - Implementar thread periódica;
//  • 3.º Passo - Colocar o fator de carga na thread;
//  • 4.º Passo - Alterar a política de escalonamento na thread;
//  • 5.º Passo - Rodar os dois programas em paralelo e fazer analise.

#include <unistd.h>
#include <iostream>
#include <signal.h>
#include <time.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int periodo, prioridade, fator_Carga, politica_Escalonamento;
    int clock_id = CLOCK_REALTIME;

    cout << "Informe o pedriodo da tarefa (ms): " << endl;
    cin >> periodo;
    cout << "Informe a prioridade da tarefa: " << endl;
    cin >> prioridade;
    cout << "Informe o fator de carga da tarefa: " << endl;
    cin >> fator_Carga;
    cout << "Informe a politica de escalonamento: " << endl;
    cin >> politica_Escalonamento;

    int timer_create(clock_id);

    return 0;
}
