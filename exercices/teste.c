#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Frutaria{
    char sabor[50];
    char cor[50];
    float peso; // Gramas
    int tempoDeVida; // Dias
} frutaria;


int main(int argc, char const *argv[])
{
    frutaria morango;
    strcpy(morango.sabor, "Azedinho");
    strcpy(morango.cor, "Vermelho");
    morango.peso = 10;
    morango.tempoDeVida = 5;

    printf("\n%s", morango.sabor);
    printf("\n%s", morango.cor);
    printf("\n%f", morango.peso);
    printf("\n%d", morango.tempoDeVida);

    return 0;
}
