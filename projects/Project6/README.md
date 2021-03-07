# Projeto 6 - MergeSort com Thread
### Gabriel Henrique da Silva Gava

## **1. Objetivo:**
<p>
Implemente o método de merge sort usando threads paralelas. Em seu projeto considere que o vetor será dividido em no máximo DEZESSEIS partes. Com isso é necessário aplicar um método de ordenação clássico em cada uma dessas partes, antes de iniciar as operações de merge.

Teste seu programa medindo o tempo consumido para a realização dos merges considerando a execução com 1, 2, 4 e 8 threads. Use como entrada os arquivos de entrada do Projeto 05 (vetor.dat).

Entrega: 08/03, no classroom

</p>

## **2. Compilação:**
Para compilar basta exucutar o seguinte comando no terminal:

```
gcc -pthread -o main main.c
```

E para executar
```
./main
```

## **3. Observações**
O array ordenado se encontra em um arquivo chamado array.dat. O tempo de escrita deste arquivo não foi considerado pra contagem de tempo da ordenação.