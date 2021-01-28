#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int prior;
    struct no * prox;
} Node;

void Print(Node * inicioFila){
    Node * posicaoAtual = inicioFila;
    
    do {

        printf("[%d] --> ",posicaoAtual->prior);
        posicaoAtual = posicaoAtual->prox;

    } while(posicaoAtual != NULL);

    printf("NULL\n");
}


Node * Atende(Node * inicioFila){

    Node * posicaoAtual = inicioFila;
    Node * posicaoAnterior = NULL;

    Node * menorPrioridade = inicioFila;
    Node * posicaoAnteriorMenorPrioridade = NULL;
    
    do {

        if(posicaoAtual->prior < menorPrioridade->prior){
            menorPrioridade = posicaoAtual;
            posicaoAnteriorMenorPrioridade = posicaoAnterior;
        }

        posicaoAnterior = posicaoAtual;
        posicaoAtual = posicaoAtual->prox;

    } while(posicaoAtual != NULL);

    // Validar inicial da fila ?
    if(menorPrioridade == inicioFila){
        inicioFila = inicioFila->prox;

    } else {

        posicaoAnteriorMenorPrioridade->prox = menorPrioridade->prox;
    }

    free(menorPrioridade);

    return inicioFila;

}


int main(int argc, char const *argv[])
{
    Node * node1 = (Node *) malloc(sizeof(Node));
    Node * node2 = (Node *) malloc(sizeof(Node));
    Node * node3 = (Node *) malloc(sizeof(Node));
    Node * node4 = (Node *) malloc(sizeof(Node));

    node1->prior = 2;
    node2->prior = 5;
    node3->prior = 6;
    node4->prior = 7;

    node1->prox = node2;
    node2->prox = node3;
    node3->prox = node4;
    node4->prox = NULL;

    Print(node1);
    node1 = Atende(node1);
    Print(node1);

    return 0;
}
