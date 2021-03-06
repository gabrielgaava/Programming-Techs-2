#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

    int N;

    scanf("%d", &N);
    char array[N][10000];

    for(int i = 0; i < N; i++){
        scanf("%s\n", &array[i][0]);
    }

    puts("Saida: \n");

    for(int i = 0; i < N; i++){
        printf("%s ", array[i]);
    }


    return 0;

}
