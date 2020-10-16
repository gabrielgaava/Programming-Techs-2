#include <stdlib.h>
#include <stdio.h>
#include <math.h>  

// Retorna o valor em Radianos da conversão de Graus
float convertDeegreToRad(int degree){
    return degree * ( M_PI / 180.0 ); 
}

// Retornar -1 se for mais proximo de @bottom e 1 se for mais proximo de @superior
int checkDiference(float bottom, float target, float superior){

    float bottomDifference = fabs(target - bottom);
    float superiorDifference = fabs(target - superior);

    if(bottomDifference < superiorDifference) return -1;
    else return 1;
}

// Adiciona dados ao arquivo
void updateFle(int degree, float seno, float cos, int isApproximated){
    FILE * file = fopen("./Files/senocosseno.txt", "a+");

    // Verifica abertura do arquivo
    if(file == NULL) {
        printf("! Erro ao criar/abrir arquivo 'senocosseno.txt'\n");
    }

    // Adiciona os dados no arquivo
    else {
        float radian = convertDeegreToRad(degree);
        fprintf(file, "%d - %f - %f - %f\n", degree, radian, seno, cos);
        printf("%d - %f - %f - %f\n", degree, radian, seno, cos);
    }

    fclose(file);
}

// Busca por resultados no arquivo
void checkTrigo(float targetSeno){

    // Variavies
    FILE * file;
    int readFlag = 1, degree = 0, lastDegree = 0;
    float seno = 0, cos = 0, lastSeno = 0, lastCos = 0;

    file = fopen("./Files/trigo.txt", "r");

    // Verifica abertura do arquivo
    if(file == NULL) puts("Erro de leitura do arquivo: trigo.txt");

    // Começa a leitura do arquivo
    while(EOF != readFlag){

        lastSeno = seno; lastCos = cos; lastDegree = degree;

        readFlag = fscanf(file, "%d\n%f\n%f\n", &degree, &seno, &cos);

        if(targetSeno == seno) {
            updateFle(degree, seno, cos, 0);
        }

        else if((lastSeno < targetSeno) && (targetSeno < seno)) {
            
            if(checkDiference(lastSeno, targetSeno, seno) == 1) {
                updateFle(degree, seno, cos, 1);
            } 
            
            else {
                updateFle(lastDegree, lastSeno, lastCos, 1);
            }
            

            break;
        }

        

    }

    fclose(file);

}

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
