#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 40
#define TRUE 1
#define FALSE 0


// Estrutura de Dados
typedef struct no {
     char pal[20];
     int urg;
     struct no *prox; 
} Elem;

int bufferCount = 0;
FILE * outputFile, * inputFile;
Elem * Buffer;


// Cria uma lista circular com "n" posições. Sendo size = n
Elem * createRingBuffer(int size){

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


// Le, printa e conta todos os nós da lista
void readList(Elem * ringBuffer){

    Elem * currentNode = NULL;
    int listSize = 0;

    if(ringBuffer == NULL) printf("\nLista vazia!");

    else {

        currentNode = ringBuffer;

        do {
            printf("[%s %d] --> ", currentNode->pal, currentNode->urg);
            listSize++;
            currentNode = currentNode->prox;

        } while(currentNode != ringBuffer);
        
    }

    puts("");
    printf("\n> [%d] Elementos percorridos\n", listSize);

}


// Insere um registro no Buffer
Elem * insertData(char word[20], int urg, Elem * writePointer){

    int wasFound = 0;

    // Buffer está Lotado 40/40
    if(bufferCount == BUFFER_SIZE) printf("> Buffer lotado \n");

    else {

        strcpy(writePointer->pal, word);
        writePointer->urg = urg;
        writePointer = writePointer->prox;
        bufferCount++;

    }

    return writePointer;
    
}


// Remove um registro do Buffer
Elem * deleteData(Elem * readPointer, Elem * writePointer){
    
    // Escreve no arquivo
    fprintf(outputFile, "%s\n", readPointer->pal);

    // Caso a palavra removida seja PRTY 
    if(strcmp(readPointer->pal, "PRTY") == 0) {

        // Limpa o valor
        strcpy(readPointer->pal, "\0");
        int jumpValue = readPointer->urg;

        for(int i = 0; i < jumpValue; i++){
            readPointer = readPointer->prox;

            // Caso tenha chegado ao ultimo valor inserido
            if(readPointer->prox == writePointer) {
                i = jumpValue;
            }
        }
        
    } else {
        
        strcpy(readPointer->pal, "\0");
        readPointer->urg = -1;
        readPointer = readPointer->prox;

    }

    bufferCount--;
    return readPointer;
}

// Le o arquivo "pacotes.dat" 
void readFile(Elem * ringBuffer){

    Elem * writePointer = ringBuffer;
    Elem * readPointer = ringBuffer;

    
    int fileEntries = 0;

    // Valores de entrada do arquivo
    int intA, intB; char string[20];

    // Leitura até o fim do arquivo
    while(fscanf(inputFile, "%d %s %d\n", &intA, string, &intB) == 3){

        if(intA == 0) {
            writePointer = insertData(string, intB, writePointer);
            fileEntries++;
        }

        else if (intA == 1){
            readPointer = deleteData(readPointer, writePointer);
        }

    }

    puts("");
    printf("> %d Entradas lidas \n", fileEntries);
    printf("> %d Elementos no Buffer\n", bufferCount);
    puts("");

}


// Função Principal
int main(int argc, char const *argv[])
{

    Buffer = createRingBuffer(BUFFER_SIZE);

    // Arquivos que serão utilizados
    outputFile = fopen("lidos.dat", "w+");
    inputFile = fopen("pacotes.dat", "r");

    readFile(Buffer);
    readList(Buffer);

    return 0;

}
