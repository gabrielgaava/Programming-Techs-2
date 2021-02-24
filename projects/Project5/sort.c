#include <stdio.h>

/* Print the actual state of vector */
void printVector(float array[], int size){
    
    for(int i = 0; i < size; i++){
        printf("[%f]", array[i]);
    }

    printf("\n");


}

// Insertion Sort Implementations - GeeksForGeeks.org
void InsertionSort(float array[], int size){    

    int i, key, j;

    for(i = 0; i < size; i++){
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = key;
        
    }

}

// Shell Sort Implementations - Wikipedia.org
void ShellSort(float array[], int size){

    int i, j, value;
    int h = 1;

    // Find the ideal "H Value"
    while (h < size) {
        h = 3 * h + 1;
    }

    while(h > 0){

        for(i = h; i < size; i++){
            value = array[i];
            j = i;

            while(j > h-1 && value <= array[j - h]){
                array[j] = array[j - h];
                j = j - h;
            }

            array[j] = value;
        }

        // Small the "H Value"
        h = h/3;
    }
    

}

/* Quick Sort Implementations - Wikipedia.org */
void QuickSort(float array[], int began, int end){

	int i = began;
    int j = end-1;
    int aux;
    float pivo = array[(began + end) / 2];

	while(i <= j)
	{
		while(array[i] < pivo && i < end)
		{
			i++;
		}

		while(array[j] > pivo && j > began)
		{
			j--;
		}
		if(i <= j)
		{
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;
			i++;
			j--;
		}
	}
    
	if(j > began) QuickSort(array, began, j+1);
	if(i < end) QuickSort(array, i, end);
}

// Linear Search Implementation
int LinearSearch(float array[], float findingValue, int size){

    for(int i = 0; i < size; i++){
        if(abs(findingValue - array[i])  < 0.0001) return i;
    }

    return -1;

}

// Binary Search Implemantation with Recursion
int BinarySearch(float array[], float findingValue, int low, int high){

    int mid = (low + high) / 2;

    if(abs(findingValue - array[mid]) < 0.0001) return mid;

    if(low >= high) return -1;

    else {

        if(array[mid] < findingValue) return BinarySearch(array, findingValue, mid+1, high);
        else return BinarySearch(array, findingValue, low, mid-1);

    }

}