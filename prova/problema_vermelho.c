#include <stdio.h>
#include <math.h> 
#include <stdlib.h> 
#include <limits.h> 


int main(int argc, char const *argv[]) {

    // Numero de discos na 1a torre
    int n;

    // Numero de movimentos feitos 
    int k;

    // Apenas verificando os inputs
    int flag;

    int A, B, C = 0;

    // Lendo os valores de N e de K
    flag = scanf("%d %d", &n, &k);

    A = n - k;
    B = k;
    C = k - 1;

    if(A < 0) A = 0;
    if(B < 0) B = 0;
    if(C < 0) C = 0;

    printf("%d %d %d", A, B ,C);

    return 0;

}
