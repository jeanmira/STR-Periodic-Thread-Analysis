#include "tarefa.h"

Tarefa::Tarefa()
{
    int periodo, prioridade, fatorCarga;
    string politicaEscalonamento;

    std::cout << "Informe o periodo:" << std::endl;
    std::cin >> periodo;
    this->periodo = periodo;
    std::cout << "Informe a prioridade:" << std::endl;
    std::cin >> prioridade;
    this->prioridade = prioridade;
    std::cout << "Informe o fator de carga:" << std::endl;
    std::cin >> fatorCarga;
    this->fatorCarga = fatorCarga;
    std::cout << "Informe a politica de escalonamento:" << std::endl;
    std::cin >> politicaEscalonamento;
    this->politicaEscalonamento = politicaEscalonamento;

    if (this->politicaEscalonamento == "OTHER")
    {
        this->politica = {.sched_priority = 0};
    }
    else if (this->politicaEscalonamento == "FIFO")
    {
        this->politica = {.sched_priority = 1};
    }
    else if (this->politicaEscalonamento == "RR")
    {
        this->politica = {.sched_priority = 2};
    }
}

Tarefa::~Tarefa()
{
}

void Tarefa::setPeriodo(int per)
{
    this->periodo = per;
}
void Tarefa::setPrioridade(int pri)
{
    this->prioridade = pri;
}
void Tarefa::setFatorCarga(int fat)
{
    this->fatorCarga = fat;
}
void Tarefa::setPoliticaEscalonamento(string pol)
{
    this->politicaEscalonamento = pol;
}

int Tarefa::getPeriodo()
{
    return this->periodo;
}
int Tarefa::getPrioridade()
{
    return this->prioridade;
}
int Tarefa::getFatorCarga()
{
    return this->fatorCarga;
}
string Tarefa::getPoliticaEscalonamento()
{
    return this->politicaEscalonamento;
}

void Tarefa::cargaGenerica(int load)
{
    while (true)
    {
        for (long long int i = 0; i < load * 1000; i++)
        {
            /* Execultando */
        }
    }
}

void Tarefa::escalonamento()
{

    //politica.sched_priority = prioridade;

    if (politicaEscalonamento == "OTHER")
    {
        //std::cout << "OTHER" << std::endl;
        if (sched_setscheduler(getpid(), SCHED_OTHER, &politica) == -1)
            perror("Politica_Escalonamento_OTHER");
    }
    else if (politicaEscalonamento == "FIFO")
    {
        //std::cout << "FIFO" << std::endl;
        if (sched_setscheduler(getpid(), SCHED_FIFO, &politica) == -1)
            perror("Politica_Escalonamento_FIFO");
    }
    else if (politicaEscalonamento == "RR")
    {
        //std::cout << "RR" << std::endl;
        if (sched_setscheduler(getpid(), SCHED_RR, &politica) == -1)
            perror("Politica_Escalonamento_RR");
    }

    if (sched_getscheduler(getpid()) == SCHED_OTHER)
    {
        cout << "Politica Escalonamento OTHER" << endl;
    }
    else if (sched_getscheduler(getpid()) == SCHED_FIFO)
    {
        cout << "Politica Escalonamento FIFO" << endl;
    }
    else if (sched_getscheduler(getpid()) == SCHED_RR)
    {
        cout << "Politica Escalonamento RR" << endl;
    }
}
