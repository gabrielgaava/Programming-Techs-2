# Aula 4 - 13/10/2020

## **1. Subprogramas**
Laços de repetição permitem que o programa execute um conjunto de instruções por diversas vezes. Mas se essas instruções estiverem espalhadas ao longo do programa, uma vez em cada lugar, não podemos usar laços.  

Para isso podemos definir esse conjunto de código como um subprograma (função), que é chamado em cada lugar que deveriamos executar esse conjunto.

## **1.2 Fluxo**
Quando é chamado um subprograma, o programa principal efetua um desvio de fluxo de execução para a função alvo a cada chamada, retornando para o ponto seguinte após o termino desta função. 

## **1.3 Parâmetros**
São dados que o programa deve passar ao subprograma como informações necessárias ao seu funcionamento. Pode não existir parâmetros caso o subprograma não necessite.  

Deve haver correspondência na ordem e quantidade dos parametros esperados e passados ao subprograma. 

## **1.4 Subprogramas em C**
Estrutura: TipoFunção NomeFunção( Lista_de_Parâmetros )
```c
int NomeFuncao(int item1, int item2) {

    //...
    // Corpo do Subprograma
    //...

}
```

## **1.5 Escopo**
Um subprograma pode ter variaveis declaradas internamente. Essas variaveis não podem ser acessadas de fora do subprograma.  

Isso define o que chamamos de **escopo de uma variavel**.
Em C o escopo pode ser **global, local ou de bloco**

## **1.6 Escopo Local**
E o escopo interno (local) a um subprograma. É composto pelas variaveis declaradas DENTRO do subprograma


## **1.7 Escopo Global**
É aquele em que a variável pode ser vista / acessada a partir de qualquer ponto do programa. Em C uma variável tem escopo global quando declarada fora de qualquer função. 

```c
int variavelGlobal = 10;

int  main(int argc, char const *argv[]) {

    // {...}

}
```

