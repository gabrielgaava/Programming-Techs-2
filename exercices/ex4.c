#include <stdio.h>
#include <stdlib.h>

// Leita N números e calcule a média e quantos números estão acima da média

int main(int argc, char const *argv[])
{   

    int size, i, count = 0;
    float media = 0;

    printf("Quantos numeros deseja inserir: ");
    scanf("%d", &size);
    printf("\n");

    int array[size];

    for(i = 0; i < size; i++){
        printf("Informe o numero %d: ", i+1);
        scanf("%d", &array[i]);
    }

    // Calcula média
    for(i = 0; i < size; i++){
        media = media + array[i];
    }

    media = media / size;

    for(i = 0; i < size; i++){
        if(array[i] > media) count++;
    }

    printf("\n\n===============");
    printf("\nMedia: %.2f", media);
    printf("\nQuantidade acima: %d\n", count);


    return 0;
}



