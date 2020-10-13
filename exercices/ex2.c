#include <stdlib.h>
#include <file.h>

/*
Escreva um programa que leia os dados do arquivos criado no ex1.c e escreva um novo arquivo ( diferente do anterior ) 
contendo os mesmos valores, intercalados pelas letras do alfabeto ( uma letra entre cada dois números)
*/

// Char = 65 => A 
// Char = 90 => Z

int main(int argc, char const *argv[])
{
  FILE * input, output;

  char letter = 65; // -> A

  int buffer;

  // Arquivo de Leitura
  input = fopen("file_ex1.txt", "r");
  // Arquivo de Escrita
  output = fopen("file_ex2.txt", "w")

  while(!feof(input)) {

    fscanf(input, "%d", &buffer);
    fprintf(output, "%d", buffer);

    fscanf(input, "%d", &buffer);
    fprintf(output, "%d", buffer);

    fprintf(output, "%c", letter);
    letter ++;

    // Começa o Alfabeto de novo
    if(letter > 90) letter = 65;

  }

   fclose(input);
   fclose(output);

  return 0;
}
