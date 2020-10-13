#include <stdlib.h>
#include <file.h>

/*
Escreva um trecho de programa em que se abra um arquivo contendo inteiros 
aleatórios e se descarte todos valores negativos ao salvar o arquivo novamente
*/

int main(int argc, char const *argv[]) {
  FILE * input, output;

  int buffer;

  // Arquivo de Leitura
  input = fopen("input.txt", "r");

  // Arquivo de Escrita
  output = fopen("output.txt", "w")

  // Copia inteiros positivos para outro arquivo
  while(!feof(input)) {

    fscanf(input, "%d", &buffer);

    if(buffer > 0)
      fprintf(output, "%d", buffer);

  }

  // Fecha os arquivos
  fclose(input);
  fclose(output);

  // Renomeia para manter a nova versão para
  remove("input.txt");
  rename("output.txt", "input.txt");
  
  return 0;
}
