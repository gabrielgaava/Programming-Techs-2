# Aula 1 - 01/10/2020

### **Bibliografia:**
Tanembaum, A.M; et al., "Data Structures using C and C++", Prentice-Hall, 1996  
Cormen, T.H. et al., "Algoritmos: Teoria e Práticas", Campus 2012  

### **Avaliação**
Três provas escritas  
Entre 12 e 15 testes, sendo descartadas as tres piores notas  
Média = 1xP1 + 2xP2 + 3xP3 + 2xTestes + 2xProjs, se Projs >= 5  

### **Observações**
Utilizar o Linux ao invez do Windows  
Página da disciplina: https://www.dcce.ibilce.unesp.br/~aleardo/cursos/atp2/

## 1. Arquitetura de Von Neumann  

**CPU:** Unidade de Controle + Unidade Lógica Aritmética  
> Unidade de Controle: Conjunto de Registradores (Stack Pointer, Program Counter)  

**Memoria:** Conjunto de "posições" de armazenamento. 


**Barramento:** é um conjunto de linhas de comunicação que permitem a interligação entre dispositivos, como a CPU, a memória e outros periféricos.

## 2. Inteiros x Ponto Flutuante
Inteiros são representados por binários com ou sem bit de sinal. Ocupam 32 ou 64 bits  
Valores de ponto flutuante são representados por dois valores binários. Uma para a mantissa e outra para o expoente em base 10.  

## 3. Caracteres
Representados a partir do código [ASCII](https://www.ascii-code.com/)  
Originalmente eram representados por 1 byte

## 3. Tipos compostos
**Homogeneos** =  Valores armazenados são todos do memso tipo  
```c 
int vet[100]  
int matriz[20][50]   
char nome[40] 
```  

**Heterogêneos** = Valores armazenados podem ser de tipos diferentes, porém previamente definidos

## 4. Testes de decisão
**Decisão simples**
```c 
if (a == b) c = a;
else a = c;
``` 

**Decisão simples**
```c 
switch (a) {
  case 0   : doSomething(0); break;
  case 1   : doSomething(1); break;
  case 2   : doSomething(2); break;
  default  : doNothing(); break;
}
``` 

## 5.Laços de repetição  
Laço enumeravel for()
```c 
for (i = 0; i < N; i++) { ... }
``` 

Laço não enumeravel while()
```c 
while { ... }
// or
do { ... } while ()
``` 


