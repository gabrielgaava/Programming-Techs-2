#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
    float x, y, mass;
} point;

// Calculates de distance beetwen 2 points
float pointDistance(point a, point b){
    float xDif = b.x - a.x;
    float yDif = b.y - a.y;
    return sqrt((xDif * xDif) + (yDif * yDif));
}

// Calculates de Mass Center of a list o points
point findCenterPoint(point pointsList[], int size){

    point centerPoint;
    float M = 0, Xcm = 0, Ycm = 0;

    for(int i = 0; i < size; i++){
        // Calculates the total mass amount
        M = M + pointsList[i].mass;
        // Calculates the x sum
        Xcm = Xcm + pointsList[i].x;
        // Calculates the Y sum
        Ycm = Ycm + pointsList[i].y;
    }

    centerPoint.x = Xcm / M;
    centerPoint.y = Ycm / M;
    centerPoint.mass = M;
    

    return centerPoint;
}

// Main function
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

    // Alocating memory space
    point pointsList[entrySize];
    point readPoint;
    readPoint.mass = 1;

    // Read all points entry and store
    for(i = 0; i < entrySize; i++) {
        fscanf(inputFile, "%f %f\n", &readPoint.x, &readPoint.y);
        pointsList[i] = readPoint;
    }

    // Finds the center point of the coordinates array
    point centerPoint = findCenterPoint(pointsList, entrySize);

    // Now, we'll find the most close point from de center
    point closerPoint = pointsList[0];
    float distance = pointDistance(pointsList[0], centerPoint);
    
    // Compares the distance between every point and the center
    // And choose the closer
    for(i = 1; i < entrySize; i++){
        if(distance > pointDistance(pointsList[i], centerPoint)){
            closerPoint = pointsList[i];
        }
    }

    printf("Ponto (%.2f, %.2f)\n", closerPoint.x, closerPoint.y);

    return 0;
}
