# Projeto 05 - Ordenação (vários métodos)

## **1. Objetivo**
Escrever um programa para fazer ordenação de um vetor de floats. Esse programa deve ser capaz de ordenar usando os métodos **insertion**, **shell** e **quicksort**. Deve também ser capaz de fazer **buscas** por determinados elementos no vetor.

A entrada do programa é um conjunto de valores lidos de um arquivo **(vetor.dat)** e um segundo conjunto de valores lidos de um outro arquivo **(busca.dat)**. A escolha pelo algoritmo de ordenação e pelo método de busca deve ser feito a partir de um **menu**.

A saída do programa deve ser um arquivo (resultado.dat) contendo uma linha para cada valor buscado, sendo que o conteúdo dessa linha, quando o valor for encontrado, deve ser da forma (não escrever os colchetes na saída):
```
[índice da posição encontrada] [valor contido naquela posição] [valor buscado]
```

Você deverá incluir no seu programa a medição do tempo gasto nas tarefas de ordenação, quando for o caso,  e de busca, considerando que as seguintes medidas deverão ser fornecidas:

1. Tempo de ordenação
2. Tempo de busca
3. Tempo total (ordenação mais busca)  


## **2. Organização do Projeto**

Todos os algoritmos de ordenação serão construidos no arquivo ```sort.c``` enquanto a execução principal do programa sera escrita no arquivo ```main.c```


## **3. Compilação e Execução**

Para facilitar a execução foi utilizado o GNU Makefile que nos permite executar uma sequencia de comandos de compilação atravez de um único comandos simples.

- Para compilar e executar o programa basta executar no terminal:  ```make all```  

- Para apenas a compilação:  ```make compile```  

- Apenas para executar:  ```make run```