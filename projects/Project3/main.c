#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// Global Values
int boardSize = 0;
int solutionsCount = 0;
int* board;
FILE * tempFile;

void createOutputFile(){

    // READ BUFFER
    char line[86];

    FILE * outputFile = fopen("rainha.out", "w+");
    tempFile = fopen("temp.txt", "r");

    if(outputFile == NULL) 
        printf(">> Erro ao criar arquivo de saida!\n");

    fprintf(outputFile, "%d\n\n", solutionsCount);

    while(fgets(line, sizeof(line), tempFile) != NULL){
        printf("%s", line);
        fprintf(outputFile, "%s", line);
    }

    fclose(tempFile);
    fclose(outputFile);
    remove ("temp.txt");
}

/* Init the all the board's positions with 0 */
void initBoard(){
    board = (int *)malloc(boardSize * boardSize * sizeof(int));
    int i, j;

    for(i = 0; i < boardSize; i++){
        for(j = 0; j < boardSize; j++){
            // board[i][j]
            board[i * boardSize + j] = 0;
        }
    }
}

/* Print the actual state of the board in terminal */
void printSolution(){
    solutionsCount++;
    //printf("\nSolution %d: \n", solutionsCount);
    int i, j;
    for(i = 0; i < boardSize; i++){
        for(j = 0; j < boardSize; j++){
            // board[i][j]
            //printf("%d  ", board[i * boardSize + j]);
            fprintf(tempFile, "%d ", board[i * boardSize + j]);
        }
        //printf("\n");
        fprintf(tempFile, "\n");
    }
    fprintf(tempFile, "\n\n");
}

// Check if the cell (row,column) is under attack by any
// other queen or not.
int canPlace(int row, int col){
    int i, j;

    // Checking the row on left side
    for(i = 0; i < col; i++){
        if(board[row * boardSize + i])
            return false;
    }

    // Checking the upper diagonal on left side
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(board[i * boardSize + j])
            return false;
    }

    // CHecking the lower diagonal on left side
    for(i = row, j = col; j>=0 && i<boardSize ; i++, j--){
        if(board[i * boardSize + j])
            return false;
    }

    return true;
}

// function where are really implementing 
// the backtracking algorithm for put N Queens on board
int solveNQueens(int col){

    // If all queens are already placed
    if(col == boardSize){
        printSolution();
        return true;
    }

    bool res = false;
    for (int i = 0; i < boardSize; i++){

        // Verify if this position isn't under attack
        if(canPlace(i, col)){

            // Now, this place have a queen
            board[i * boardSize + col] = 1;

            // RECURSIVE:
            // Make result true if any placement is possible
            res = solveNQueens(col + 1) || res;

            // If this placing queen doesn't lead to a solution
            // then we remove queen form board[i][col]
            board[i * boardSize + col] = 0;
            
        }

    }

    return res;
}

// Main function
int main(int argc, char const *argv[]){

    tempFile = fopen("temp.txt", "w+");
    if(tempFile == NULL) {
        printf(">> Erro na criacao de arquivo temporario\n");
        return 0;
    }

    // Reading the board size and validating it
    bool flag = true;
    while(flag) {
        printf("Insert the board size(N): ");
        scanf("%d", &boardSize);
        if(boardSize > 3 && boardSize < 33) 
            flag = false;
        else {
            printf(">> Entrada deve ser entre 4 e 32\n\n");
            flag = true;
        }
    } 

    // Initializing the board values with 0
    initBoard();

    // Start the algorithm with 0 queens place
    if(solveNQueens(0) == false){
        printf("\n>> Solução não encontrada");
        fclose(tempFile);
        return 0;
    }

    fclose(tempFile);
    createOutputFile();
    printf("\n\n>> %d Solutions found!\n", solutionsCount);
    
    return 0;
}
