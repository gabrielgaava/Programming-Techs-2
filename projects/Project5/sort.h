#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
/* ^^ these are the include guards */

/* Prototypes for the functions */

/* Print the actual state of vector */
void printVector(double array[], int size);

/* Insertion Sort Implementations - GeeksForGeeks.org */
void InsertionSort(double array[], int size);

// Shell Sort Implementations - Wikipedia.org
void ShellSort(double array[], int size);

/* Quick Sort Implementations - Wikipedia.org */
void QuickSort(double array[], int began, int end);

/* Return the indice if it finds, or -1 if not */
int LinearSearch(double array[], double findingValue, int size);

/* Return the indice if it finds, or -1 if not */
int BinarySearch(double array[], double findingValue, int low, int high);

#endif