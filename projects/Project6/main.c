// Gabriel Henrique da Silva Gava

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

// Valores Globais
double *array;
int ARRAY_SIZE;
int NUM_OF_THREADS;
int NUMBER_PER_THREAD;
int OFFSET;

// Estrutura responsavel por armazenas os registros
// de tempo da aplicação
typedef struct timeRecord {
  long int seconds;
  long int nanoseconds;
} TimeRecord;

// Calcula o tempo de execução dado um inicio e um fim
TimeRecord getRecordTime(struct timespec start, struct timespec end){
  TimeRecord record;

  if(end.tv_sec < start.tv_sec){
    end.tv_nsec += 1000000000;
    end.tv_sec--;
  }

  record.seconds = (long)(end.tv_sec - start.tv_sec);
  record.nanoseconds = (long)(end.tv_nsec - start.tv_nsec);

  return record;
}

// Printa o tempo
void printTime(struct timespec S_SortTime, struct timespec E_SortTime) {
  TimeRecord timeRecord = getRecordTime(S_SortTime, E_SortTime);
  printf("%ld.%09ld", timeRecord.seconds, timeRecord.nanoseconds);
}

// Cria array de double de acordo com o arquivo escolhido
double * allocateArray(char fileName[]){

    printf("\n> Lendo arquivo de entrada '%s'..\n", fileName);

    FILE * input = fopen(fileName, "r");
    double * array = malloc(1 * sizeof(double));
    double value;
    ARRAY_SIZE = 0;

    // Read, create and store dynamically
    while (fscanf(input, "%lf\n", &value) != EOF){
        ARRAY_SIZE++;
        array = realloc(array, ARRAY_SIZE * sizeof(double));
        array[ARRAY_SIZE - 1] = value;
    }

    printf("> [%d] Entradas armazenadas\n", ARRAY_SIZE);
    fclose(input);
    return array;
    
}

// <-- !! Apenas para desenvolvimento !! -->
// Imprime no terminal o array
void printArray(int start, int end) {
  for (int i = start; i < end; i++) {
    printf("%lf\n", array[i]);
  }
}

// <-- !! Apenas para desenvolvimento !! -->
// Imprime o array em um arquivo
void createArrayFile(){
  FILE * Output = fopen("./array.dat", "w+");
  for (int i = 0; i < ARRAY_SIZE; i++) {
    fprintf(Output,"%lf\n", array[i]);
  }
}

// Função "merge" do MergeSort
int Merge(int left, int middle, int right) {
  int i = 0, j = 0, k = 0;
  int left_length = middle - left + 1;
  int right_length = right - middle;
  double left_array[left_length];
  double right_array[right_length];

  // Copia os valores para o array da esquerda 
  for (int i = 0; i < left_length; i ++) {
    left_array[i] = array[left + i];
  }

// Copia os valores para o array da direita 
  for (int j = 0; j < right_length; j ++) {
    right_array[j] = array[middle + 1 + j];
  }

  i = j = 0;

  // Escolhe da esquerda e rireita e copia
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

  // Copia os valores remanescente para o array
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

// Algoritmo de ordenação MergeSort
void MergeSort(int left, int right) {
  if (left < right) {
      int middle = left + (right - left) / 2;
      MergeSort(left, middle);
      MergeSort(middle + 1, right);
      Merge(left, middle, right);
  }
}

// Função executada pelos threads
void * Threads_MergeSort(void * arg){
  int threadID = (long)arg;
  int left = threadID * (NUMBER_PER_THREAD);
  int right = (threadID + 1) * (NUMBER_PER_THREAD) - 1;

  if(threadID == NUM_OF_THREADS - 1) right += OFFSET;

  int middle = left + (right - left)/2;

  if(left < right) {
    MergeSort(left, right);
    MergeSort(left+1, right);
    Merge(left, middle, right);
  }

  printf("\n|> Thread %d ordenou intervalo [%d, %d]: ",threadID, left, right);
  //printArray(left, right);

  return NULL;
}

// Junsta as partes do array
void MergeSections(int number, int aggr){
  for(int i = 0; i < number; i = i + 2) {
        int left = i * (NUMBER_PER_THREAD * aggr);
        int right = ((i + 2) * NUMBER_PER_THREAD * aggr) - 1;
        int middle = left + (NUMBER_PER_THREAD * aggr) - 1;
        if (right >= ARRAY_SIZE) {
            right = ARRAY_SIZE - 1;
        }
        Merge(left, middle, right);
    }
    if (number / 2 >= 1) {
        MergeSections(number / 2, aggr * 2);
    }
}

// Função principal
int main(int argc, char const *argv[]){

  int arraySizeOption;
  char fileName[100];
  struct timespec S_SortTime, E_SortTime;
  
  printf("\n|= = = = = = =  M E N U  = = = = = = =|");
  printf("\n|> Selecione o tamanho do array:");
  printf("\n\n[1] 120.000 Elementos");
  printf("\n[2] 240.000 Elementos");
  printf("\n[3] 480.000 Elementos");

  printf("\n\nSua escolha: ");
  scanf("%d", &arraySizeOption);

  // Handle File
  if(arraySizeOption == 1) strcpy(fileName, "vetor120k.dat");
  else if(arraySizeOption == 2) strcpy(fileName, "vetor240k.dat");
  else if(arraySizeOption == 3) strcpy(fileName, "vetor480k.dat");
  else {
    printf("\nOpção invalida. Programa encerrado!\n");
    return 0;
  }

  printf("\n\n|> Informe a quantidade de Threads (1, 2, 4 ou 8):");
  printf("\nSua escolha: ");
  scanf("%d", &NUM_OF_THREADS);

  if(NUM_OF_THREADS > 8 || NUM_OF_THREADS < 1 
  || NUM_OF_THREADS == 3 || NUM_OF_THREADS == 5 
  || NUM_OF_THREADS == 6 || NUM_OF_THREADS == 7) {
    printf("\n|> Numero de threads invalido!\n");
    return 0;
  }

  system("clear");

  array = allocateArray(fileName);
  NUMBER_PER_THREAD = ARRAY_SIZE / NUM_OF_THREADS;
  OFFSET = ARRAY_SIZE % NUM_OF_THREADS;

  // Iniciando Lógica dos Threads
  pthread_t threads[NUM_OF_THREADS];
  clock_gettime(CLOCK_REALTIME, &S_SortTime);
  long i;

  // Cria todos os Threads
  for(i = 0; i < NUM_OF_THREADS; i++){
    int rc = pthread_create(&threads[i], NULL, Threads_MergeSort, (void *)i);
    if(rc) {
      printf("\n> Erro criação de Threads!");
      return 0;
    }
  }

  // Espera todos Threads terminarem
  for(i = 0; i < NUM_OF_THREADS; i++){
    pthread_join(threads[i], NULL);
  }
  
  // Agrupa os resultados
  MergeSections(NUM_OF_THREADS, 1);

  clock_gettime(CLOCK_REALTIME, &E_SortTime);
  printf("\n|> Tempo levado para ordenacao: ");
  printTime(S_SortTime, E_SortTime);
  printf("\n");

  createArrayFile();

  return 0;
}
