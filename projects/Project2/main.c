#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
    float x, y, mass;
} point;


float pointDistance(float xa, float xb, float ya, float yb){
    float xDif = xb - xa;
    float yDif = yb - ya;
    return sqrt((xDif * xDif) + (yDif * yDif));
}

int main(int argc, char const *argv[])
{
    // Open file
    FILE * inputFile;

    // Try to open the file
    if((inputFile = fopen("input.txt", "r")) == NULL){
        printf("!! Error on file oppening.\n");
        printf("> Exiting\n");
        return 0;
    }

    int entrySize, i;
    float value1, value2;

    // Read the entry size of the file
    fscanf(inputFile, "%d\n", &entrySize);

    // Read all points entry
    for(i = 0; i < entrySize; i++) {
        fscanf(inputFile, "%f %f\n", &value1, &value2);
        printf("Coordenada %d: (%.2f,%.2f)\n", i+1, value1, value2);
    }

    return 0;
}
