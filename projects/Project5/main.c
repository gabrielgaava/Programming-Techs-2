#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Header files from external source code
#include "sort.h"

// !! For development purpose only !!
#define ARRAY_SIZE 10000
int entryCount = 0;
int searchCount = 0;

// Support struct to store de results
typedef struct data {
    
    long sortNanoTime;
    long sortSegTime;

    long searchNanoTime;
    long searchSegTime;

    char sortMethod[20];
    char searchMethod[20];
    int withSearch; 

} Report;

// Read the vetor.dat file and create the vector dynamically
float * readEntryFile(){

    printf("\n> Lendo arquivo de entrada...\n");

    FILE * input = fopen("./test/teste02/vetor.dat", "r");
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
    fclose(input);
    return array;
    
}

// Read the "busca.data" file and apply the search method
void * readSearchFile(float array[], int arraySize, int applyBinary){

    FILE * input = fopen("./test/teste02/busca.dat", "r");
    FILE * output = fopen("./test/teste02/resultado2.dat", "w+");
    float value, finalValue; int tempIndex; searchCount = 0;

    // Read and search elements of file
    while (fscanf(input, "%f\n", &value) != EOF){

        searchCount++;
        if(applyBinary) tempIndex = BinarySearch(array, value, 0, arraySize);
        else tempIndex = LinearSearch(array, value, arraySize);

        if(tempIndex == -1) finalValue = 0.0;
        else finalValue = array[tempIndex];

        fprintf(output, "%d %f %f\n", tempIndex, finalValue, value);
    }

    fclose(input);
    fclose(output);

}

// Print de Terminal Menu 
int printMenu(){

    int option = -1, validOption = 0;
    char term;
    system("clear");

    while(!validOption){

        printf("\n= = = = = = = = = = =   M E N U   = = = = = = = = = = =");
        printf("\n\n[1] - Busca sem ordenacao");
        printf("\n[2] - Ordenacao por InsertionSort e busca Sequencial");
        printf("\n[3] - Ordenacao por ShellSort e busca Sequencial");
        printf("\n[4] - Ordenacao por QuickSort e busca Sequencial");
        printf("\n[5] - Ordenacao por InsertionSort e busca Binaria");
        printf("\n[6] - Ordenacao por ShellSort e busca Binaria");
        printf("\n[7] - Ordenacao por QuickSort e busca Binaria");
        printf("\n[8] - Sair\n");
        printf("\n= = = = = = = = = = = = = = = = = = = = = = = = = = = =");
        printf("\n\nSUA ESCOLHA: ");
        scanf("%d", &option);

        if(option != -1 && option > 0 && option <= 8) {
            validOption = 1;
        } else {
            printf("\n> Opcao invalida!");
        }
    }

    return option;
    
}

// This function is responsible for execute the sort algorithm according 
// to the option chosen in the menu
Report handleSort(int option){

    // For time calculation
    struct timespec sortStart, sortEnd;
    struct timespec searchStart, searchEnd;
    Report newReport;

    system("clear");

    // Creating array from input file
    float * array = readEntryFile();

    printf("\n> Iniciando ...");

    switch (option){
    case 1:
        /* code */
        break;

    case 2:
        printf("\n> Aplicando InsertionSort ...");
        clock_gettime(CLOCK_REALTIME, &sortStart);
        InsertionSort(array, entryCount);
        clock_gettime(CLOCK_REALTIME, &sortEnd);

        printf("\n> Aplicando busca Sequencial ...");
        clock_gettime(CLOCK_REALTIME, &searchStart);
        readSearchFile(array, entryCount, 0);
        clock_gettime(CLOCK_REALTIME, &searchEnd);

        newReport.withSearch = 1;
        strcpy(newReport.sortMethod, "InsertionSort");
        strcpy(newReport.searchMethod, "Sequencial");

        break;

    case 3:
        printf("\n> Aplicando ShellSort ...");
        clock_gettime(CLOCK_REALTIME, &sortStart);
        ShellSort(array, entryCount);
        clock_gettime(CLOCK_REALTIME, &sortEnd);

        printf("\n> Aplicando busca Sequencial ...");
        clock_gettime(CLOCK_REALTIME, &searchStart);
        readSearchFile(array, entryCount, 0);
        clock_gettime(CLOCK_REALTIME, &searchEnd);

        newReport.withSearch = 1;
        strcpy(newReport.sortMethod, "ShellSort");
        strcpy(newReport.searchMethod, "Sequencial");

        break;
    
    case 4:
        printf("\n> Aplicando QuickSort ...");
        clock_gettime(CLOCK_REALTIME, &sortStart);
        QuickSort(array, 0, entryCount);
        clock_gettime(CLOCK_REALTIME, &sortEnd);

        printf("\n> Aplicando busca Sequencial ...");
        clock_gettime(CLOCK_REALTIME, &searchStart);
        readSearchFile(array, entryCount, 0);
        clock_gettime(CLOCK_REALTIME, &searchEnd);

        newReport.withSearch = 1;
        strcpy(newReport.sortMethod, "QuickSort");
        strcpy(newReport.searchMethod, "Sequencial");
        break;
    
    case 5:
        printf("\n> Aplicando InsertionSort ...");
        clock_gettime(CLOCK_REALTIME, &sortStart);
        InsertionSort(array, entryCount);
        clock_gettime(CLOCK_REALTIME, &sortEnd);

        printf("\n> Aplicando busca Binaria ...");
        clock_gettime(CLOCK_REALTIME, &searchStart);
        readSearchFile(array, entryCount, 1);
        clock_gettime(CLOCK_REALTIME, &searchEnd);

        newReport.withSearch = 1;
        strcpy(newReport.sortMethod, "InsertionSort");
        strcpy(newReport.searchMethod, "Binaria");
        break;

    case 6:
        printf("\n> Aplicando ShellSort ...");
        clock_gettime(CLOCK_REALTIME, &sortStart);
        ShellSort(array, entryCount);
        clock_gettime(CLOCK_REALTIME, &sortEnd);

        printf("\n> Aplicando busca Binaria ...");
        clock_gettime(CLOCK_REALTIME, &searchStart);
        readSearchFile(array, entryCount, 1);
        clock_gettime(CLOCK_REALTIME, &searchEnd);

        newReport.withSearch = 1;
        strcpy(newReport.sortMethod, "ShellSort");
        strcpy(newReport.searchMethod, "Binaria");
        break;

    case 7:
        printf("\n> Aplicando QuickSort ...");
        clock_gettime(CLOCK_REALTIME, &sortStart);
        QuickSort(array, 0, entryCount);
        clock_gettime(CLOCK_REALTIME, &sortEnd);

        printf("\n> Aplicando busca Binaria ...");
        clock_gettime(CLOCK_REALTIME, &searchStart);
        readSearchFile(array, entryCount, 1);
        clock_gettime(CLOCK_REALTIME, &searchEnd);

        newReport.withSearch = 1;
        strcpy(newReport.sortMethod, "QuickSort");
        strcpy(newReport.searchMethod, "Binaria");
        break;

    case 8:
        return;
        break;
    
    default:
        break;
    }

    newReport.sortNanoTime = sortEnd.tv_nsec - sortStart.tv_nsec;
    newReport.sortSegTime = sortEnd.tv_sec - sortStart.tv_sec;

    newReport.searchNanoTime = searchEnd.tv_nsec - searchStart.tv_nsec;
    newReport.searchSegTime = searchEnd.tv_sec - searchStart.tv_sec;


    return newReport;

}

// Primary function
int main(int argc, char const *argv[])
{

    int option;
    char key;
    Report results;

    /* = = = MENU LOOP === */

    do {
        
        option = printMenu();
        results = handleSort(option);

        if(option != 8 && option != 1){

            system("clear");
            printf("\n = = = = = = =   R E S U L T A D O S   = = = = = = =\n");
            printf("\n- ORDENACAO: ");
            printf("\n> Elementos no vetor: %d elementos", entryCount);
            printf("\n> Metodo de ordencao: %s", results.sortMethod);
            printf("\n> Tempo de ordenacao: %ldns -> %ldseg", results.sortNanoTime, results.sortSegTime);

            if(results.withSearch) {
                printf("\n\n- BUSCA: ");
                printf("\n> Metodo de busca: %s", results.searchMethod);
                printf("\n> Tempo de busca: %ldns -> %ldseg", results.searchNanoTime, results.searchSegTime);
            }

            printf("\n\n> Tempo TOTAL: %ldns -> %ldseg", results.searchNanoTime + results.sortNanoTime, results.sortSegTime + results.searchSegTime);

            printf("\n\n= = = = = = = = = = = = = = = = = = = = = = = = = = =\n");

            puts("\nPressione ENTER para continuar...");
            getchar();
            getchar();

        }

    } while(option != 8);

    /* = = = = = = = = = = */


    return 0;
}
