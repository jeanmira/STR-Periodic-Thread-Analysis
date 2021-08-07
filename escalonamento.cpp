#include "escalonamento.h"

//----- Construtor padrão
Escalonamento::Escalonamento()
{
}

//----- Destrutor padrão
Escalonamento::~Escalonamento()
{
}

//----- Cria os objetos e adiciona os parâmetros
void Escalonamento::setParametros(Tarefa novasTarefas)
{
    tarefas.push_back(novasTarefas);
}
//----- Seleciona um dos dois escalonadores
void Escalonamento::selecionaEscalonamento()
{
    for (int i = 0; i < tarefas.size(); i++)
    {
        if (tarefas[i].getPolıticaEscalonamento() == "SCHED_FIFO")
        {
            fcfs();
        }
        else if (tarefas[i].getPolıticaEscalonamento() == "SCHED_RR")
        {
            rrsp();
        }
        else
        {
            cout << "Opcao de Escalonador Errada" << endl;
        }
    }
}

//----- Escalonamento por FCFS (First Come, First Served)
void Escalonamento::fcfs()
{
    cout << "----- FCFS (First Come, First Served) -----" << endl;
    //----- Limpar os dados que são compartilhados
    for (int i = 0; i < p.size(); i++)
    {
        p[i].limpaDados();
    }

    Processo aux(0, 0, 0, 0);
    // Ordena a "fila" vetor de processos pela ordem de criação
    for (int i = 0; i < p.size(); i++)
    {
        for (int j = i + 1; j < p.size(); j++)
        {
            if (p[j].getCriacao() < p[i].getCriacao())
            {
                aux = p[i];
                p[i] = p[j];
                p[j] = aux;
            }
        }
    }
    p[0].setTempoEspera(0);
    p[0].setTempoTotal(p[0].getDuracao());
    p[0].setTempIni(0);
    p[0].setTempFin(p[0].getDuracao());
    int tempexectot = 0;
    for (int i = 1; i < p.size(); i++)
    {
        tempexectot += p[i - 1].getDuracao();
        p[i].setTempIni(tempexectot);
        p[i].setTempFin(tempexectot + p[i].getDuracao());
        p[i].setTempoEspera(tempexectot - p[i].getCriacao());
        p[i].setTempoTotal(p[i].getTempoEspera() + p[i].getDuracao());
    }

    tempexectot += p[p.size() - 1].getDuracao();
    //---------------------------------------------------
    for (int i = 0; i < p.size(); i++)
    {
        // 0 = ' ', 1 = ##, 2 = --
        for (int j = 0; j < tempexectot; j++)
        {
            if (j < p[i].getCriacao() || j >= p[i].getTempFin())
                p[i].setEstado(0);
            else if (j < p[i].getTempFin() && j >= p[i].getTempIni())
                p[i].setEstado(1);
            else
            {
                p[i].setEstado(2);
            }
        }
    }
}

//----- Escalonamento por Round-Robin com prioridade
void Escalonamento::rrsp()
{
    cout << "----- Escalonamento por Round-Robin com quantum = 2s, sem prioridade -----" << endl;
    int tempoTotal = 0;
    for (int i = 0; i < p.size(); i++)
    {
        p[i].limpaDados();
        tempoTotal += p[i - 1].getDuracao();
    }
    tempoTotal += p[p.size() - 1].getDuracao();

    Processo aux(0, 0, 0, 0);
    // Ordena a "fila" vetor de processos pela ordem de criação
    for (int i = 0; i < p.size(); i++)
    {
        for (int j = i + 1; j < p.size(); j++)
        {
            if (p[j].getCriacao() < p[i].getCriacao())
            {
                aux = p[i];
                p[i] = p[j];
                p[j] = aux;
            }
        }
    }
    vector<Processo> temp = p;
    vector<Processo> arrumaPosExecucao = p;
    queue<Processo> copia;
    aux = p[0];

    int clock = 0;

    for (int tick = 0; tick < tempoTotal; tick++)
    {
        // Conforme o tempo passa coloca o processo dentro da fila
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i].getCriacao() <= tick && temp[i].getCriacao() != -1)
            {
                copia.push(temp[i]);     // Adiciona na fila
                temp[i].invalidaDados(); // Mata o vetor temporário
            }
        }

        //Maior prioridade
        if (clock == quantum || copia.front().getDuracao() == clock)
        {
            copia.front().diminuiTempo(quantum); // Diminui o tempo do processo que está executando
            // Se o tempo do vetor que está na cópia estiver com tempo zerado apaga esse vetor para ele não entrar na análise novamente
            if (copia.front().getDuracao() <= 0)
            {
                for (int k = 0; k < p.size(); k++)
                {
                    if (aux.getId() == p[k].getId())
                    {
                        arrumaPosExecucao[k].invalidaDados();
                    }
                }
                copia.pop();         // Apaga o vetor
                aux = copia.front(); // Adiciona o próximo na CPU
            }
            // Se ele nao tiver com o tempo zerado incrementa um no contexto dele
            else
            {
                for (int k = 0; k < p.size(); k++)
                {
                    if (aux.getId() == p[k].getId())
                    {
                        p[k].incrementaContexto(); // Aumenta troca de contexto
                    }
                }
                copia.push(copia.front()); //Adiciona o primeiro no final da fila
                copia.pop();               // Apaga o primeiro
                aux = copia.front();       // Adiciona o novo primeiro a CPU
            }
            clock = 0; // Zera o clock
        }
        // Preenche o vetor de estados de acordo com o processo que está sendo executado no momento
        for (int i = 0; i < p.size(); i++)
        {

            if (aux.getId() == p[i].getId())
            {
                p[i].setEstado(1);
            }
            else if (p[i].getCriacao() <= tick && arrumaPosExecucao[i].getCriacao() != -1)
            {
                p[i].setEstado(2);
            }
            else
            {
                p[i].setEstado(0);
            }
        }
        clock++;
    }
}