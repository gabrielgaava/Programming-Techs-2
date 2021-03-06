// Importing Libraries
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

// Global Variables
#define INPUT_SIZE 500000
double *array;
int size = 0;
int NUM_THREADS;
int NUMBERS_PER_THREAD;
int OFFSET;


// Time Structures
struct timespec initialSortTime, finalSortTime;
struct timespec initialSearchTime, finalSearchTime;

struct timeRegistry {
  long int seconds;
  long int nanoseconds;
};

struct timeRegistry sortRegistry;
struct timeRegistry searchRegistry;

struct timeRegistry getTimeRegistry(struct timespec initial, struct timespec final) {
  struct timeRegistry registry;

  if (final.tv_nsec < initial.tv_nsec) {
    final.tv_nsec += 1000000000;
    final.tv_sec--;
  }

  registry.seconds = (long)(final.tv_sec - initial.tv_sec);
  registry.nanoseconds = final.tv_nsec - initial.tv_nsec;

  return registry;
}

// Print the sorting time
void printSortTime() {
  sortRegistry = getTimeRegistry (initialSortTime, finalSortTime);
  printf("Tempo de ordenação: %ld.%09ld\n", sortRegistry.seconds, sortRegistry.nanoseconds);

}

// Read Input Array
void *getInputArray() {
  FILE *input = fopen("./vetor120k.dat", "r");

  array = (double *) malloc(INPUT_SIZE * sizeof(double));

  while(fscanf(input, "%lf", &array[size]) != EOF) size++;

  fclose(input);
}

// Print Array
void printArray() {
  int i = 0;

  for (i = 0; i < size; i++) {
    printf("%lf\n", array[i]);
  }
}

/* merge function */
int merge(int left, int middle, int right) {
    int i = 0;
    int j = 0;
    int k = 0;
    int left_length = middle - left + 1;
    int right_length = right - middle;
    int left_array[left_length];
    int right_array[right_length];
    
    /* copy values to left array */
    for (int i = 0; i < left_length; i ++) {
        left_array[i] = array[left + i];
    }
    
    /* copy values to right array */
    for (int j = 0; j < right_length; j ++) {
        right_array[j] = array[middle + 1 + j];
    }
    
    i = 0;
    j = 0;
    /** chose from right and left arrays and copy */
    while (i < left_length && j < right_length) {
        if (left_array[i] <= right_array[j]) {
            array[left + k] = left_array[i];
            i ++;
        } else {
            array[left + k] = right_array[j];
            j ++;
        }
        k ++;
    }
    
    /* copy the remaining values to the array */
    while (i < left_length) {
        array[left + k] = left_array[i];
        k ++;
        i ++;
    }
    while (j < right_length) {
        array[left + k] = right_array[j];
        k ++;
        j ++;
    }

    return 0;
}

// Merge Sort
void merge_sort(int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        merge_sort(left, middle);
        merge_sort(middle + 1, right);
        merge(left, middle, right);
    }
}

void *thread_merge_sort(void* arg) {
    int thread_id = (long)arg;
    int left = thread_id * (NUMBERS_PER_THREAD);
    int right = (thread_id + 1 ) * (NUMBERS_PER_THREAD) - 1;
    if (thread_id == NUM_THREADS - 1) {
        right += OFFSET;
    }
    int middle = left + (right - left) / 2;
    if (left < right) {
        merge_sort(left, right);
        merge_sort(left + 1, right);
        merge(left, middle, right);
    }
    return NULL;
}

void merge_sections_of_array(int number, int aggregation) {
    for(int i = 0; i < number; i = i + 2) {
        int left = i * (NUMBERS_PER_THREAD * aggregation);
        int right = ((i + 2) * NUMBERS_PER_THREAD * aggregation) - 1;
        int middle = left + (NUMBERS_PER_THREAD * aggregation) - 1;
        if (right >= size) {
            right = size - 1;
        }
        merge(left, middle, right);
    }
    if (number / 2 >= 1) {
        merge_sections_of_array(number / 2, aggregation * 2);
    }
}

// Main function
int main(int argc, char const *argv[])
{
    getInputArray();

    printf("Digite a quantidade de Threads: ");
    scanf("%d", &NUM_THREADS);
    NUMBERS_PER_THREAD = size / NUM_THREADS;
    OFFSET = size % NUM_THREADS;

    puts("------------------------------------------------------------------------");
    pthread_t threads[NUM_THREADS];
    clock_gettime(CLOCK_REALTIME, &initialSortTime);
    long i;

    // Creating Threads
    for(long i = 0; i < NUM_THREADS; i++) {
        int rc = pthread_create(&threads[i], NULL, thread_merge_sort, (void *)i);
        if (rc){
            printf("Error");
            exit(-1);
        }
    }

    for( i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    merge_sections_of_array(NUM_THREADS, 1);



    clock_gettime(CLOCK_REALTIME, &finalSortTime);
    printSortTime();

    return 0;
}
