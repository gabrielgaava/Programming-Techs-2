#include <stdlib.h>
#include <file.h>

/*
Escreva um trecho de programa em que se abra um arquivo contendo inteiros 
aleatórios e se descarte todos valores negativos ao salvar o arquivo novamente
*/

int main(int argc, char const *argv[]) {
  FILE * input, output;

  int buffer, numberLength;

  // Arquivo de Leitura
  input = fopen("input.txt", "r");

  // Verifica quantidade entradas
  while(fscanf(input, "%d ", &buffer) > 0 && !feof(input)) {
    if(buffer > 0) numberLength++;
  }

  // Variaveis auxiliar
  int numbers[numberLength], i = 0;

  // Popula o Array
  while(fscanf(input, "%d ", &buffer) > 0 && !feof(input)) {
    if(buffer > 0) {
      numbers[i] = buffer;
      i++;
    }
  }

  // Fecha os arquivos
  fclose(input);

  // Abre de novo e salva com dados atualizados
  input = fopen("input.txt","w");

  for(i = 0; i < numberLength; i++){
    fprintf(input, "%d ", numbers[i]);
  }

  
  return 0;
}
