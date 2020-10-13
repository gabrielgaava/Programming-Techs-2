#include <stdlib.h>
#include <stdio.h>

// Exercicios 1:
// Criar um arquivo que contenha 100 números pares gerados com o rand()

int main(int argc, char const *argv[])
{

  // Variables
  FILE *file;
  int i, x;

  // File opening
  file = fopen("file_ex1.txt", "w");


  for(i = 0; i < 100; i++){
    x = rand();
    while (x % 2) x = rand();
    fprintf(file, "%d\n", x);
  }

  return 0;
}
