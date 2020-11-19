#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// Global Value
int boardSize;
int* board;

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
void printBoard(){
    int i, j;
    for(i = 0; i < boardSize; i++){
        for(j = 0; j < boardSize; j++){
            // board[i][j]
            printf("%d  ", board[i * boardSize + j]);
        }
        printf("\n");
    }
}

// Check if the cell (row,column) is under attack by any
// other queen or not.
int canPlace(int row, int column){
    int i, j;

    // Checking if thre's a queen in row or column
    for(i = 0; i < boardSize; i++){
        // borad[row][i] == 1  || board[i][column]
        if((board[row * boardSize + i] == 1) || (board[i * boardSize + column] == 1))
            return 0;
    }

    // Checking for diagonals
    for(i = 0; i < boardSize; i++){
        for(j = 0; j < boardSize; j++){
            if(((i+j) == (row+column)) || ((i-j) == (row-column))) {
                //board[i][j]
                if(board[i * boardSize + j] == 1)
                    return 0;
            }
        }
    }

    // It's all safe here
    return 1;
}

// function where are really implementing 
// the backtracking algorithm.
int insertNQueens(int n){
    int i, j;

    // If n is 0, solution found
    if(n == 0) return 1;

    for(i = 0; i < boardSize; i++){
        for(j = 0; j < boardSize; j++){

            // Check if we can place a queen here or not
            // Queen will not be place if the funcition return false (0)
            if((canPlace(i, j)) && (board[i * boardSize + j] != 1)) {

                
                // Now, this place have a queen
                board[i * boardSize + j] = 1;

                // Recursão
                if(insertNQueens(n - 1) == 1) {
                    return 1;
                }

                // board[i][j] = 0
                board[i * boardSize + j] = 0;
            } 
            
        }

    }

    return 0;
}


int main(int argc, char const *argv[]){
    
    // Reading the board size
    printf("Insert the board size(N): ");
    scanf("%d", &boardSize);

    // Initializing the board values
    initBoard();

    // Start the algoritgmo
    insertNQueens(boardSize);

    // Print the results
    printBoard();

    return 0;
}
