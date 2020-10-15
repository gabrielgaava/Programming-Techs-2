# Aula 5 - 15/10/2020

## **1. Observações sobre Escopo**
Evitem usar variáveis globais, a menos que seja estrimamente necessário, pois consomem mais espaço de memória.

## **2. Passagem de Parâmetros**
Variáveis locais a um subprograma podem ser passadas para outro subprograma com parametros. Essa passagem pode ser passada de duas formas: **por copia e por referência**.  

 ## **3. Manipulando Ponteiros em C**
 Uma referencia nada mais é que o endereço de uma variável. Em C, passar endereços e acessar seus valores é bem simples.  

 Um ponteiro é uma variável que armazena o endereço de algum valor na memória.   

 ## **3.1. Declaração**
 A sintaxe de declaração de ponteiro em C é dada por:
 ```c
/* Tipo * nomePonteiro */
int * nomePonteiro;
 ``` 

 ## **3.2. Atribuição**
Supondo que p1 e p2 sejam ponteiros, então é possivel copiar o endereço de uma variável para outra
 ```c
p1 = p2
 ``` 

 Por outro lado, se quiser pegar o **valor** armazenado em um enderço basta utilizar o *
  ```c
int var = *nomePonteiro;
 ``` 

Copia o valor var para o valor de endereço de nomePonteiro
```c
int *nomePonteiro = var;
 ``` 

 ## **3.3. Passagem**
 Passagem de endereço para função:
 ```c
// Recebe dois ponteiros de inteiro como parametro
void Função(int * x, int * y);

// Passa o endereço de var1 e de var2
Função(&var1, &var2);
```