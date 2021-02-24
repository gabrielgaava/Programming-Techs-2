#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n, i;
    int Abel, Bebel;

    char result[1000];


    // Le o tamanho de N
    scanf("%d", &n);

    // Lendo entradas dos jogos
    for(i = 0; i < n; i++) {

        scanf("%d %d", &Abel, &Bebel);

        // Verificando se é par ou impar
        if((Abel + Bebel) % 2 == 0) result[i] = 'A';
        else result[i] = 'B';

    }


    // Exebindo resultados
    for(i = 0; i < n; i++) {
        printf("%c\n", result[i]);
    }

    return 0;
}
