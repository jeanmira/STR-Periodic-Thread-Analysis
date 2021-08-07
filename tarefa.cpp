#include "tarefa.h"

Tarefa::Tarefa(int per, int pri, int fat, string pol)
{
    this->periodo = per;
    this->prioridade = pri;
    this->fatorCarga = fat;
    this->polıticaEscalonamento = pol;
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
void Tarefa::setPolıticaEscalonamento(string pol)
{
    this->polıticaEscalonamento = pol;
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
string Tarefa::getPolıticaEscalonamento()
{
    return this->polıticaEscalonamento;
}

void Tarefa::cargaGenerica(int carga)
{
    for (int i = 0; i < carga * 1000; i++)
    {
        /* Execultando */
    }
}
