  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define MINES 20

int board[ROWS][COLS];
int revealed[ROWS][COLS];

void initializeBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 0;
            revealed[i][j] = 0;
        }
    }
}

void plantMines() {
    srand(time(NULL));
    for (int i = 0; i < MINES; i++) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (board[row][col] == -1) {
            i--;  
        } else {
            board[row][col] = -1;  
            for (int r = row - 1; r <= row + 1; r++) {
                for (int c = col - 1; c <= col + 1; c++) {
                    if (r >= 0 && r < ROWS && c >= 0 && c < COLS && board[r][c] != -1) {
                        board[r][c]++;
                    }
                
                }
            }
        }
    }
}

void reveal(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || revealed[row][col]) {
        return;
    }
    revealed[row][col] = 1;
    if (board[row][col] == 0) {
        for (int r = row - 1; r <= row + 1; r++) {
            for (int c = col - 1; c <= col + 1; c++) {
                reveal(r, c);
            }
        }
    }
}

void displayBoard() {
    printf("Current Board:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (revealed[i][j]) {
                if (board[i][j] == -1) {
                    printf("* ");
                } else {
                    printf("%d ", board[i][j]);
                }
             }else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    printf("-----****------MiNeSwEePeR------****-----\n");

    initializeBoard();
    plantMines();

    while (1) {
        displayBoard();

        int row, col;
        printf("Enter row and column: ");
        scanf("%d %d", &row, &col);

        if (board[row][col] == -1) {
            printf("Game over!\n");
            for(int i=0;i<ROWS;i++)
            {
                for(int j=0;j<COLS;j++)
                {
                    if(board[i][j]==-1)
                    {
                        printf("* ");
                    }
                    else{
                        printf("%d ",board[i][j]);
                    }
                }
            printf("\n");
            }
            break;
        }

        reveal(row, col);

        int revealedCount = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (revealed[i][j]) {
                    revealedCount++;
                }
            }
        }

        if (revealedCount == ROWS * COLS - MINES) {
            printf("Congratulations! You win!\n");
            break;
        }
    }

   return main(); 
}
