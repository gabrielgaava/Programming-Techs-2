#include <stdlib.h>
#include <stdio.h>
#include <math.h>  

// Retorna o valor em Radianos da conversão de Graus
float convertDeegreToRad(int degree){
    return degree * ( M_PI / 180.0 ); 
}

// Procura a aproximação do grau com regra de 3
float findDegree(float fixedDegree, float fixedSin, float findSin){
    
    return (fixedDegree * findSin) / fixedSin;

}

// Procura aproximação de Cosseno para grau nao inteiro
float findCos(float findSin){

    float findCos = sqrt(1 - pow(findSin, 2));
    return findCos;

}

// Adiciona dados ao arquivo
void updateFle(float degree, float seno, float cos, int isApproximated){
    FILE * file = fopen("./Files/senocosseno.txt", "a+");
    char endline[50] = "\n";

    // Verifica abertura do arquivo
    if(file == NULL) {
        printf("! Erro ao criar/abrir arquivo 'senocosseno.txt'\n");
    }

    // Adiciona os dados no arquivo
    else {
        float radian = convertDeegreToRad(degree);
        fprintf(file, "%f - %f - %f - %f\n", degree, radian, seno, cos);
        printf("%f - %f - %f - %f\n", degree, radian, seno, cos);
    }

    fclose(file);
}

// Busca por resultados no arquivo
void checkTrigo(float targetSeno){

    // Variavies
    FILE * file;
    int readFlag = 1;
    float degree = 0, lastDegree = 0;
    float seno = 0, cos = 0, lastSeno = 0, lastCos = 0;

    file = fopen("./Files/trigo.txt", "r");

    // Verifica abertura do arquivo
    if(file == NULL) puts("Erro de leitura do arquivo: trigo.txt");

    // Começa a leitura do arquivo
    while(EOF != readFlag){

        lastSeno = seno; lastCos = cos; lastDegree = degree;

        readFlag = fscanf(file, "%f\n%f\n%f\n", &degree, &seno, &cos);

        if(targetSeno == seno) {
            updateFle(degree, seno, cos, 0);
        }

        else if((lastSeno < targetSeno) && (targetSeno < seno)) {
            
            float finalDdegree = findDegree(lastDegree, lastSeno, targetSeno);
            float finalCos = findCos(targetSeno);
            updateFle(finalDdegree, targetSeno, finalCos, 1);

            break;
        }


    }

    fclose(file);

}

// Função principal
int main(int argc, char const *argv[]) {

    FILE * file;
    int readFlag = 1;
    float readSeno;

    file = fopen("./Files/seno.txt", "r");

    while(fscanf(file, "%f\n", &readSeno) != EOF){

        checkTrigo(readSeno);

    }


    fclose(file);
    
    return 0;

}
