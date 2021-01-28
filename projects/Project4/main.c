#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Estrutura de Dados
typedef struct no {
     char pal[20];
     int urg;
     struct no *prox; 
} Elem;


// Cria uma lista circular com "n" posições. Sendo size = n
Elem * createCircularList(int size){

    // Ponteiros auxiliares
    Elem * prevNode, * newNode;

    if(size >= 1){

        Elem * bufferList = (Elem *) malloc(sizeof(Elem));

        // Atribuindo dados Temporarios
        strcpy(bufferList->pal, "\0");
        bufferList-> urg = -1;
        bufferList->prox = NULL;

        prevNode = bufferList;
        
        // Agora criamos os outros N elementos
        for (int i = 2; i <= size; i++){

            newNode = (Elem *) malloc(sizeof(Elem));

            // Atribuindo dados Temporarios
            strcpy(bufferList->pal, "\0");
            newNode-> urg = -1;
            newNode->prox = NULL;

            // Linka o ultimo nó ao novo nó
            prevNode->prox = newNode;

            // Atualiza o ultimo Nó
            prevNode = newNode;
        }

        // Linka o ultimo nó ao primeiro
        prevNode->prox = bufferList;

        return bufferList;
    }

    return NULL;
}


// Le todos os nós da lista e conta
void readList(Elem * beginning){

    Elem * currentNode = NULL;
    int listSize = 0;

    if(beginning == NULL) printf("\nLista vazia!");

    else {

        currentNode = beginning;

        do {
            printf("[%s %d] --> ", currentNode->pal, currentNode->urg);
            listSize++;
            currentNode = currentNode->prox;

        } while(currentNode != beginning);
        
    }

    printf("\n> [%d] Elementos percorridos\n", listSize);

}


// Insere um registro na lista circular
// 1. Procura uma posição livre
// 2. Faz as atribuições
void insertData(char word[20], int urg, Elem * list){

    Elem * currentNode = list;
    int wasFound = 0;

    do {

        // Posição livre
        if(strcmp(currentNode->pal, "\0") == 0){

            strcpy(currentNode->pal, word);
            currentNode->urg = urg;
            wasFound = 1;

        } else {

            currentNode = currentNode->prox;

        }

    } while(currentNode != list && !wasFound);
    
}


// Le o arquivo "pacotes.dat" 
void readFile(Elem * list){

    FILE * file = fopen("pacotes.dat", "r");
    int fileEntries = 0;

    // Valores de entrada do arquivo
    int intA, intB; char string[20];

    // Leitura até o fim do arquivo
    while(fscanf(file, "%d %s %d\n", &intA, string, &intB) == 3){

        if(intA == 0) {
            insertData(string, intB, list);
            fileEntries++;
        }

    }

    printf("> %d Entradas lidas \n", fileEntries);

}


// Função Principal
int main(int argc, char const *argv[])
{

    Elem * bufferList = createCircularList(40);
    readFile(bufferList);
    readList(bufferList);

    return 0;
}
