#include "tarefa.h"

Tarefa::Tarefa(string n, int p, int f)
{
    this->nome = n;
    this->periodo = p;
    this->fatorCarga = f;
}

void Tarefa::setNome(string n)
{
    this->nome = n;
}
void Tarefa::setPeriodo(int p)
{
    this->periodo = p;
}
void Tarefa::setFatorCarga(int f)
{
    this->fatorCarga = f;
}
string Tarefa::getNome()
{
    return this->nome;
}
int Tarefa::getPeriodo()
{
    return this->periodo;
}
int Tarefa::getFatorCarga()
{
    return this->fatorCarga;
}

void Tarefa::cargaGenerica(int carga)
{
    for (int i = 0; i < carga * 1000; i++)
    {
        /* Execultando */
    }
}
