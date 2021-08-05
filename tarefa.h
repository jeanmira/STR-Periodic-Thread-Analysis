#ifndef TAREFA_H
#define TAREFA_H

#include <iostream>

using namespace std;

class Tarefa
{
private:
    string nome;
    int periodo;
    int fatorCarga;

public:
    Tarefa(string n, int p, int f);
    void setNome(string n);
    void setPeriodo(int p);
    void setFatorCarga(int f);
    string getNome();
    int getPeriodo();
    int getFatorCarga();
    void cargaGenerica(int carga);
};

#endif