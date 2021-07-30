# **Sistemas de Tempo Real - Implementação e Análise de Thread Periódica no Linux**

[![Generic badge](https://img.shields.io/badge/Status-Andamento-brightgreen.svg)](https://shields.io/)

## Descrição do Projeto:
O trabalho consiste na implementação de threads ou tarefas periódicas no Linux. Será utilizado o Timer padrão POSIX e o sinal enviado por ele para implementar o comportamento periódico de uma thread. 

### Passos para a implementação:
      • 1.º Passo - Ler o manual das duas bibliotecas (Tratamento do alarme com o sigwait), para detectar perda de deadline;
      • 2.º Passo - Implementar thread periódica;
      • 3.º Passo - Colocar o fator de carga na thread;
      • 4.º Passo - Alterar a política de escalonamento na thread;
      • 5.º Passo - Rodar os dois programas em paralelo e fazer analise.
