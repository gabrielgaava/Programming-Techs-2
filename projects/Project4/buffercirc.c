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

// Valores globais de ampĺo acesso
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
        
        // Agora criamos os outros N-1 elementos
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


// Le, printa e conta todos os nós do buffer
void printBuffer(Elem * writerPointer, Elem * readPointer){

    Elem * currentNode = NULL;
    int listSize = 0;

    if(Buffer == NULL) printf("\nLista vazia!");

    else {

        currentNode = Buffer;

        printf("\n=========== BUFFER ===========\n\n");

        // Percorre todos elementos até voltar ao "inicio" novamente
        do {
            
            // Exibie local do ponteiro de Escrita
            if(currentNode == writerPointer) printf("(W)");
            // Exibie local do ponteiro de Leitura
            if(currentNode == readPointer) printf("(R)");

            printf("[%s, %d]-->", currentNode->pal, currentNode->urg);
            listSize++;
            currentNode = currentNode->prox;

        } while(currentNode != Buffer);

        printf("/LOOP/");
        printf("\n\n=========== ====== ===========\n");
        
    }

    puts("");
    //printf("\n> [%d] Elementos percorridos\n", listSize);

}


// Insere um registro no Buffer
Elem * insertData(char word[20], int urg, Elem * writePointer){

    // Buffer está Lotado n/n
    if(bufferCount == BUFFER_SIZE) printf("> Buffer lotado \n");

    else {

        strcpy(writePointer->pal, word);
        writePointer->urg = urg;
        writePointer = writePointer->prox;
        bufferCount++;

    }

    return writePointer;
    
}


// "Remove" um registro do Buffer
Elem * deleteData(Elem * readPointer, Elem * writePointer){
    
    // Escreve no arquivo
    fprintf(outputFile, "%s\n", readPointer->pal);

    // Caso a palavra removida seja PRTY 
    if(strcmp(readPointer->pal, "PRTY") == 0) {

        // Limpa o valor
        strcpy(readPointer->pal, "\0");
        int jumpValue = readPointer->urg;
        readPointer->urg = -1;

        // Neste caso pulamo URG posições POSSIVEIS. 
        // Visto que nao pode ultrapassar o ponteiro de escrita
        for(int i = 0; i < jumpValue; i++){
        
            // Caso tenha chegado ao ultimo valor inserido
            if(readPointer == writePointer) {
                i = jumpValue;

            // Caso contrario, apenas pula uma posição
            } else {
                //bufferCount--;
                readPointer = readPointer->prox;
            }
        }
        
    } else {
        
        // "Limpamos" o dado no Buffer 
        strcpy(readPointer->pal, "\0");
        readPointer->urg = -1;

        // Não permitir ultrapassar o ponteiro de escrita
        if(readPointer->prox != writePointer)
            readPointer = readPointer->prox;

    }

    bufferCount--;
    return readPointer;
}


// Le o arquivo "pacotes.dat" 
void readFileEntries(){

    Elem * writePointer = Buffer;
    Elem * readPointer = Buffer;

    
    int fileEntries = 0;
    int readedEntries = 0;

    // Valores de entrada do arquivo
    int intA, intB; char string[20];

    // Leitura até o fim do arquivo
    while(fscanf(inputFile, "%d %s %d\n", &intA, string, &intB) == 3){

        // Caso seja uma "inserção"
        if(intA == 0) {

            // Caso a leitura seja 'NULL' finalizamos o programa
            if(strcmp(string, "NULL") == 0) break;

            writePointer = insertData(string, intB, writePointer);
            fileEntries++;
        }

        // Caso seja uma "remoção"
        else if (intA == 1){
            readPointer = deleteData(readPointer, writePointer);
            readedEntries++;
        }

        else printf("> Entrada invalida!\n");

    }

    puts("");
    printf("> [%d]\tEntradas escritas \n", fileEntries);
    printf("> [%d]\tEntradas lidas \n", readedEntries);
    printf("> [%d]\tElementos no Buffer", bufferCount);
    puts("");

    printBuffer(writePointer, readPointer);

}


// Função Principal
int main(int argc, char const *argv[])
{

    // Cria o buffer circular
    Buffer = createRingBuffer(BUFFER_SIZE);

    // Arquivos que serão utilizados
    outputFile = fopen("lidos.dat", "w+");
    inputFile = fopen("pacotes.dat", "r");

    // Verifica abertura do arquivo
    if(outputFile == NULL || inputFile == NULL) {
        printf("> Erro na abertura dos arquivos!\n");
        return 0;
    }

    // Faz a leitura de entrada e inicia o algoritimo do buffer
    readFileEntries();

    // Fecha todos arquivos
    fclose(outputFile);
    fclose(inputFile);

    return 0;

}
