# Aula 8 - 03/11/2020

## **1. Estruturas Heterogêneas**
O que fazer para armazenar dados de tipos diferentes mas que sejam relativos ao mesmo ”objeto” ?  
Utilizamos o ```struct``` da linguagem C.

- O ”objeto”tratado deve ter um nome
- Os dados internos de informação tambem devem ser nomeados
- Para identificar completamente algo precisamos definir o nome do objeto e do campo

Exemplo: 
```c
typedef struct funcionario { 
  char nome[50];
  int reg;
  char nasc[15]
  .
  .
  .
} Func;

Func funcionario1, funcionario2;
Func listaFuncionarios[100];
```

Para acessar os campos do objeto:
```c
scanf("%d %s", &funcionario2.reg, funcionario2.estcivil);
funcionario1.reg = 180;
listaFuncionario[1].nome = "Gabriel"; 
```

## **2. Observações**
Definam estruturas como sendo globais. Isso permite que ela seja utilizavel em qualquer função do seu código  

Declarar internamente a uma função é possível mas em geral não terá serventia.