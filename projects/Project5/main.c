#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Cabeçalho para arquivo com algoritmos de ordenação
#include "sort.h"

// Defines
#define NS_PER_SECOND 1000000000

int entryCount = 0;
int searchCount = 0;

// Estrutura de suporte para armazenar resultados
typedef struct data {
    
    long sortNanoTime;
    long sortSegTime;

    long searchNanoTime;
    long searchSegTime;

    char sortMethod[20];
    char searchMethod[20];
    int withSearch; 

} Report;

// Le o arquivo vetor.dat e cria o vetor de forma dinamica
double * readEntryFile(){

    printf("\n> Lendo arquivo de entrada...\n");

    FILE * input = fopen("./test/teste01/vetor.dat", "r");
    double * array = malloc(1 * sizeof(double));
    double value;
    entryCount = 0;

    // Read, create and store dynamically
    while (fscanf(input, "%lf\n", &value) != EOF){
        entryCount++;
        array = realloc(array, entryCount * sizeof(double));
        array[entryCount - 1] = value;
    }

    printf("> [%d] Entradas armazenadas\n", entryCount);
    fclose(input);
    return array;
    
}

// Le o arquivo "busca.data" e aplica um metodo de busca para cada entrada
void readSearchFile(double array[], int arraySize, int applyBinary){

    FILE * input = fopen("./test/teste01/busca.dat", "r");
    FILE * output = fopen("./test/teste01/resultado2.dat", "w+");
    double value, finalValue; int tempIndex; searchCount = 0;

    // Read and search elements of file
    while (fscanf(input, "%lf\n", &value) != EOF){

        searchCount++;
        if(applyBinary) tempIndex = BinarySearch(array, value, 0, arraySize);
        else tempIndex = LinearSearch(array, value, arraySize);

        if(tempIndex == -1) finalValue = 0.0;
        else finalValue = array[tempIndex];

        fprintf(output, "%d %lf %lf\n", tempIndex, finalValue, value);
    }

    fclose(input);
    fclose(output);

    return;

}

// Printa no terminal um Menu
int printMenu(){

    int option = -1, validOption = 0;
    system("clear");

    while(!validOption){

        printf("\n= = = = = = = = = = =   M E N U   = = = = = = = = = = =");
        printf("\n\n[1] - Busca Sequencial sem ordenacao");
        printf("\n[2] - Busca Binaria sem ordenacao");
        printf("\n[3] - Ordenacao por InsertionSort e busca Sequencial");
        printf("\n[4] - Ordenacao por ShellSort e busca Sequencial");
        printf("\n[5] - Ordenacao por QuickSort e busca Sequencial");
        printf("\n[6] - Ordenacao por InsertionSort e busca Binaria");
        printf("\n[7] - Ordenacao por ShellSort e busca Binaria");
        printf("\n[8] - Ordenacao por QuickSort e busca Binaria");
        printf("\n[9] - Sair\n");
        printf("\n= = = = = = = = = = = = = = = = = = = = = = = = = = = =");
        printf("\n\nSUA ESCOLHA: ");
        scanf("%d", &option);

        if(option != -1 && option > 0 && option <= 9) {
            validOption = 1;
        } else {
            printf("\n> Opcao invalida!");
        }
    }

    return option;
    
}

// Recebe duas capturas de tempo e faz a subtração delas
// e armazena em uma nova estrutura
void subTimespec(struct timespec t1, struct timespec t2, struct timespec *td) {

    td->tv_nsec = t2.tv_nsec - t1.tv_nsec;
    td->tv_sec  = t2.tv_sec - t1.tv_sec;

    if (td->tv_sec > 0 && td->tv_nsec < 0) {
        td->tv_nsec += NS_PER_SECOND;
        td->tv_sec--;
    }

    else if (td->tv_sec < 0 && td->tv_nsec > 0){
        td->tv_nsec -= NS_PER_SECOND;
        td->tv_sec++;
    }

}

// Printa na tela o tempo de forma "foramtada"
void printTime(long sec, long nano, int type){

    long ms = nano / 1.0e6;

    if(ms > 0){
        if(ms > 1000) { 
            sec = sec + 1;
            ms = ms - 1000;
        }
        printf("%ld,", sec);
        if(ms < 100) printf("0");
        printf("%ld seg", ms);
    } 
    else {
        printf("0,000%ld seg", nano);
    }


}

// Função repsonsavel por lidar com a opção gerado no Menu
// Inicia e finaliza os timers
Report handleSort(int option){

    // Para calculo de tempo
    struct timespec sortStart, sortEnd;
    struct timespec searchStart, searchEnd;
    struct timespec finalSort, finalSearch;
    Report newReport;

    system("clear");

    // Cria o vetor baseado no arquivo
    // Para que na proxima iteração ele esteja DESORDENADO
    double * array = readEntryFile();

    printf("\n> Iniciando ...");

    switch (option){
        case 1: 
            printf("\n> Aplicando busca Sequencial ...");
            printf("\n");
            clock_gettime(CLOCK_REALTIME, &searchStart);
            readSearchFile(array, entryCount, 0);
            clock_gettime(CLOCK_REALTIME, &searchEnd);
            strcpy(newReport.searchMethod, "Sequencial");
            printVector(array, entryCount);
            break;

        case 2: 
            printf("\n> Aplicando busca Binaria ...");
            printf("\n");
            clock_gettime(CLOCK_REALTIME, &searchStart);
            readSearchFile(array, entryCount, 1);
            clock_gettime(CLOCK_REALTIME, &searchEnd);
            strcpy(newReport.searchMethod, "Binaria");
            break;

        case 3:
            printf("\n> Aplicando InsertionSort ...");
            printf("\n");
            clock_gettime(CLOCK_REALTIME, &sortStart);
            InsertionSort(array, entryCount);
            clock_gettime(CLOCK_REALTIME, &sortEnd);

            printf("> Aplicando busca Sequencial ...");
            printf("\n");
            clock_gettime(CLOCK_REALTIME, &searchStart);
            readSearchFile(array, entryCount, 0);
            clock_gettime(CLOCK_REALTIME, &searchEnd);

            newReport.withSearch = 1;
            strcpy(newReport.sortMethod, "Insertion Sort");
            strcpy(newReport.searchMethod, "Sequencial");

            break;

        case 4:
            printf("\n> Aplicando ShellSort ...");
            printf("\n");
            clock_gettime(CLOCK_REALTIME, &sortStart);
            ShellSort(array, entryCount);
            clock_gettime(CLOCK_REALTIME, &sortEnd);

            printf("> Aplicando busca Sequencial ...");
            printf("\n");
            clock_gettime(CLOCK_REALTIME, &searchStart);
            readSearchFile(array, entryCount, 0);
            clock_gettime(CLOCK_REALTIME, &searchEnd);

            newReport.withSearch = 1;
            strcpy(newReport.sortMethod, "Shell Sort");
            strcpy(newReport.searchMethod, "Sequencial");

            break;
        
        case 5:
            printf("\n> Aplicando QuickSort ...");
            printf("\n");
            clock_gettime(CLOCK_REALTIME, &sortStart);
            QuickSort(array, 0, entryCount);
            clock_gettime(CLOCK_REALTIME, &sortEnd);
            
            printf("> Aplicando busca Sequencial ...");
            printf("\n");
            clock_gettime(CLOCK_REALTIME, &searchStart);
            readSearchFile(array, entryCount, 0);
            clock_gettime(CLOCK_REALTIME, &searchEnd);

            newReport.withSearch = 1;
            strcpy(newReport.sortMethod, "Quick Sort");
            strcpy(newReport.searchMethod, "Sequencial");
            
            break;
        
        case 6:
            printf("\n> Aplicando InsertionSort ...");
            printf("\n");
            clock_gettime(CLOCK_REALTIME, &sortStart);
            InsertionSort(array, entryCount);
            clock_gettime(CLOCK_REALTIME, &sortEnd);

            printf("> Aplicando busca Binaria ...");
            printf("\n");
            clock_gettime(CLOCK_REALTIME, &searchStart);
            readSearchFile(array, entryCount, 1);
            clock_gettime(CLOCK_REALTIME, &searchEnd);

            newReport.withSearch = 1;
            strcpy(newReport.sortMethod, "Insertion Sort");
            strcpy(newReport.searchMethod, "Binaria");
            break;

        case 7:
            printf("\n> Aplicando ShellSort ...");
            printf("\n");
            clock_gettime(CLOCK_REALTIME, &sortStart);
            ShellSort(array, entryCount);
            clock_gettime(CLOCK_REALTIME, &sortEnd);

            printf("> Aplicando busca Binaria ...");
            printf("\n");
            clock_gettime(CLOCK_REALTIME, &searchStart);
            readSearchFile(array, entryCount, 1);
            clock_gettime(CLOCK_REALTIME, &searchEnd);

            newReport.withSearch = 1;
            strcpy(newReport.sortMethod, "Shell Sort");
            strcpy(newReport.searchMethod, "Binaria");
            break;

        case 8:
            printf("\n> Aplicando QuickSort ...");
            printf("\n");
            clock_gettime(CLOCK_REALTIME, &sortStart);
            QuickSort(array, 0, entryCount);
            clock_gettime(CLOCK_REALTIME, &sortEnd);

            printf("> Aplicando busca Binaria ...");
            printf("\n");
            clock_gettime(CLOCK_REALTIME, &searchStart);
            readSearchFile(array, entryCount, 1);
            clock_gettime(CLOCK_REALTIME, &searchEnd);

            newReport.withSearch = 1;
            strcpy(newReport.sortMethod, "Quick Sort");
            strcpy(newReport.searchMethod, "Binaria");
            break;

        case 9:
            return newReport;
            break;
        
        default:
            break;
    }

    subTimespec(sortStart, sortEnd, &finalSort);
    subTimespec(searchStart, searchEnd, &finalSearch);

    newReport.sortNanoTime = finalSort.tv_nsec;
    newReport.sortSegTime = finalSort.tv_sec;

    newReport.searchNanoTime = finalSearch.tv_nsec;
    newReport.searchSegTime = finalSearch.tv_sec;


    return newReport;

}

// Função Primaria
int main(int argc, char const *argv[]) {

    int option;
    Report results;

    /* = = = MENU LOOP === */

    do {
        
        option = printMenu();
        results = handleSort(option);

        if(option != 9){

            system("clear");
            printf("\n = = = = = = =   R E S U L T A D O S   = = = = = = =\n");

            if(option > 2) {
                printf("\n- ORDENACAO: ");
                printf("\n> Elementos no vetor: %d elementos", entryCount);
                printf("\n> Metodo de ordencao: %s", results.sortMethod);
                printf("\n> Tempo de ordenacao: ");
                printTime(results.sortSegTime, results.sortNanoTime, 0);
                printf("\n");
            }

            printf("\n- BUSCA: ");
            printf("\n> Metodo de busca: %s", results.searchMethod);
            printf("\n> Tempo de busca: ");
            printTime(results.searchSegTime, results.searchNanoTime, 0);
            
            if(option > 2) {
                printf("\n\n> Tempo TOTAL: ");
                printTime(results.sortSegTime + results.searchSegTime, results.searchNanoTime + results.sortNanoTime, 0);
            }

            printf("\n\n= = = = = = = = = = = = = = = = = = = = = = = = = = =\n");

            puts("\nPressione ENTER para continuar...");
            getchar();
            getchar();

        }

    } while(option != 9);

    /* = = = = = = = = = = */

    printf("\n> Saindo... \n");
    return 0;
}
