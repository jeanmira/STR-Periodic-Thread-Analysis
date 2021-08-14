# **Sistemas de Tempo Real - Implementação e Análise de Thread Periódica no Linux**

[![Generic badge](https://img.shields.io/badge/Status-Finalizado-brightgreen.svg)](https://shields.io/)

## Descrição do Projeto:
O trabalho consiste na implementação de threads ou tarefas periódicas no Linux. Será utilizado o Timer padrão POSIX e o sinal enviado por ele para implementar o comportamento periódico de uma thread. 

### Passos para a implementação:
      • 1.º Passo - Ler o manual das duas bibliotecas (Tratamento do alarme com o sigwait), para detectar perda de deadline;
      • 2.º Passo - Implementar thread periódica;
      • 3.º Passo - Colocar o fator de carga na thread;
      • 4.º Passo - Alterar a política de escalonamento na thread;
      • 5.º Passo - Rodar os dois programas em paralelo e fazer analise.
      
### Como executar:
      • 1.º Passo - Abrir dois terminais no Linux
      • 2.º Passo - Executar o comando: $ make
      • 3.º Passo - Digite a senha
      • 4.º Passo - Digite o valor de período (em milissegundos, de 1 ms a 999 ms)
      • 5.º Passo - Digite a prioridade da tarefa/thread
      • 6.º Passo - Digite o valor de fator de carga da CPU
      • 7.º Passo - Digite o valor de política de escalonamento (FIFO ou RR)
      • 8.º Passo - O código ira executar até o usuário digitar no terminal o comando: $ ctrl + c
