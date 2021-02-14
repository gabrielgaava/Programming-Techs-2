#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
/* ^^ these are the include guards */

/* Prototypes for the functions */

/* Print the actual state of vector */
void printVector(float array[], int size);

/* Insertion Sort Implementations - GeeksForGeeks.org */
void InsertionSort(float array[], int size);

// Shell Sort Implementations - Wikipedia.org
void ShellSort(float array[], int size);

/* Quick Sort Implementations - GeeksForGeeks.org */
void QuickSort(float array[], int low, int high);

#endif