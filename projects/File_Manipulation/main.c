#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {

    FILE * file;

    file = fopen("./Files/teste.txt", "w+");
    fprintf(file, "teste");
    fclose(file);
    
    return 0;

}
