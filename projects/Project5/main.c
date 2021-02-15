#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Header files from external source code
#include "sort.h"

// !! For development purpose only !!
#define ARRAY_SIZE 10000
int entryCount = 0;
char chosenMethod[20];


// Read the vetor.dat file and create the vector dynamically
float * readEntryFile(){

    printf("\n> Reading 'vetor.dat' file...\n");

    FILE * input = fopen("./test/teste01/vetor.dat", "r");
    float * array = malloc(1 * sizeof(float));
    float value;
    entryCount = 0;

    // Read, create and store dynamically
    while (fscanf(input, "%f\n", &value) != EOF){
        entryCount++;
        array = realloc(array, entryCount * sizeof(float));
        array[entryCount - 1] = value;
    }

    printf("> [%d] Entradas armazenadas\n", entryCount);
    return array;
    
}

// Print de Terminal Menu 
int printMenu(){

    int option, validOption = 0;

    system("clear");

    while(!validOption){

        printf("\n = = = = = = = = = = =   M E N U   = = = = = = = = = = =");
        printf("\n\n> Arquivo lido corretamente");
        printf("\n> Quantidade de elementos armazenados: %d\n", entryCount);
        printf("\n[1] - Busca sem ordenacao");
        printf("\n[2] - Ordenacao por InsertionSort e busca Sequencial");
        printf("\n[3] - Ordenacao por ShellSort e busca Sequencial");
        printf("\n[4] - Ordenacao por QuickSort e busca Sequencial");
        printf("\n[5] - Ordenacao por InsertionSort e busca Binaria");
        printf("\n[6] - Ordenacao por ShellSort e busca Binaria");
        printf("\n[7] - Ordenacao por QuickSort e busca Binaria");
        printf("\n[8] - Sair\n");
        printf("\n = = = = = = = = = = = = = = = = = = = = = = = = = = = =");
        printf("\n\nSUA ESCOLHA: ");
        scanf("%d", &option);

        if(option != -1 && option > 0 && option < 8) {
            validOption = 1;
        } else {
            printf("\n> Opcao invalida!");
        }
    }

    return option;
    
}

// This function is responsible for execute the sort algorithm according 
// to the option chosen in the menu
void handleSort(int option, float array[], struct timespec start, struct timespec end){

    switch (option){
    case 1:
        /* code */
        break;

    case 2:
        InsertionSort(array, entryCount);
        break;

    case 3:
        /* code */
        break;
    
    case 4:
        /* code */
        break;
    
    case 5:
        /* code */
        break;

    case 6:
        /* code */
        break;

    case 7:
        /* code */
        break;

    case 8:
        return;
        break;
    
    default:
        break;
    }


}

// Primary function
int main(int argc, char const *argv[])
{

    // For time calculation
    struct timespec start, end;

    // Creating array from input file
    float * array = readEntryFile();
    int option;

    /* = = = MENU LOOP === */

    do {
        
        option = printMenu();
        system("clear");
        handleSort(option, array, start, end);

    } while(option != 8);

    /* = = = = = = = = = = */
    

    long nanoTime = end.tv_nsec - start.tv_nsec;
    long segTime = end.tv_sec - start.tv_sec;

    //printf("\nVetor ordenado: \n");
    //printVector(array, ARRAY_SIZE);

    printf("\n = = = = = =   R E S U L T A D O S   = = = = = =");
    printf("\n> Elementos no vetor: %d elementos", entryCount);
    printf("\n> Metodo de ordencao: %s", chosenMethod);
    printf("\n> Tempo de ordenacao: (Nano Seg): %ld ns\n", nanoTime);
    printf("> Tempo de ordenacao: (SEG): %ld seg\n", segTime);
    printf("= = = = = = = = = = = = = = = = = = = = = = = = =\n");


    return 0;
}
