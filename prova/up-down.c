#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printVector(long array[], int start, int end){
    for(int i = start; i < end; i++){
        printf("[%ld]", array[i]);
    }
}

int binarySearchC(long array[], int l, int r, long target) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (array[mid] == target) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (array[mid] > target) 
            return binarySearchC(array, l, mid - 1, target); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearchC(array, mid + 1, r, target); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
} 

// Busca binaria decrescente
int binarySearchD(long array[], int l, int r, long target) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (array[mid] == target) 
            return mid; 
  
        // If element is bigger than mid, then 
        // it can only be present in left subarray 
        if (array[mid] < target) 
            return binarySearchD(array, l, mid - 1, target); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearchD(array, mid + 1, r, target); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
} 


int main(int argc, char const *argv[])
{
    int arraySize; // N
    int searchSize; // M
    long array[100000];
    long searchArray[100000];

    scanf("%d", &arraySize);

    for(int i = 0; i < arraySize; i++) {
        scanf("%ld", &array[i]);
    }

    scanf("%d", &searchSize);

    for(int i = 0; i < searchSize; i++) {
        scanf("%ld", &searchArray[i]);
    }

    int middle = arraySize/2;

    for(int i = 0; i < searchSize; i++) {
        int index = binarySearchC(array, 0, middle, searchArray[i]);
        if(index == -1) index = binarySearchD(array, middle, arraySize-1, searchArray[i]);
        printf("%d ", index);
    }

    printf("\n");


    return 0;
}
