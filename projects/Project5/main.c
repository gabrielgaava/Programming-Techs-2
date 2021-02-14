#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Header files from external source code
#include "sort.h"

// !! For development purpose only !!
#define ARRAY_SIZE 100000

// Create a Dynamic array
float * createArray(int sizeOfArray){
    float * array = malloc(sizeOfArray * sizeof(float));
    return array;
}

// !! For development purpose only !!
void createRandomValues(float array[], int sizeOfArray){
    printf("\n> Criando valores ...\n");
    for(int i = 0; i < sizeOfArray; i++){
        float randomValue = (float)rand()/(float )(RAND_MAX/10000000.0);
        array[i] = randomValue;
    }
}

int main(int argc, char const *argv[])
{

    // For time calculation
    struct timespec start, end;

    float * array = createArray(ARRAY_SIZE);
    createRandomValues(array, ARRAY_SIZE);
    
    printf("Vetor original: \n");
    //printVector(array, ARRAY_SIZE);

    // START: Save time of Starting
    clock_gettime(CLOCK_REALTIME, &start);

    // Execute the sorting
    InsertionSort(array, ARRAY_SIZE);

    //END: Save time of ending
    clock_gettime(CLOCK_REALTIME, &end);

    long nanoTime = end.tv_nsec - start.tv_nsec;
    long segTime = end.tv_sec - start.tv_sec;

    printf("\nVetor ordenado: \n");
    //printVector(array, ARRAY_SIZE);

    printf("\n = = = = = =   R E S U L T A D O S   = = = = = =");
    printf("\n> Tempo levado (Nano Seg): %ld ns\n", nanoTime);
    printf("> Tempo levado (SEG): %ld seg\n", segTime);
    printf("= = = = = = = = = = = = = = = = = = = = = = = = =\n");


    return 0;
}
