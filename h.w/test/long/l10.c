#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4  // 4x4 board, 8 pairs

char board[SIZE][SIZE];       // Holds the actual characters
int revealed[SIZE][SIZE];     // 1 if revealed, 0 if hidden

// Function declarations
void initializeBoard();
void shuffleBoard();
void printBoard();
int isGameOver();
void playTurn();

int main() {
    srand(time(NULL));
    initializeBoard();
    shuffleBoard();

    printf("Welcome to the Memory Game!\n");

    while (!isGameOver()) {
        printBoard();
        playTurn();
    }

    printf("Congratulations! You've matched all the pairs!\n");
    return 0;
}

// Initialize board with pairs of letters
void initializeBoard() {
    char letters[] = "AABBCCDDEEFFGGHH";  // 8 pairs
    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = letters[index++];
            revealed[i][j] = 0;  // Start hidden
        }
    }
}

// Shuffle the board randomly
void shuffleBoard() {
    for (int i = 0; i < SIZE * SIZE; i++) {
        int r1 = rand() % SIZE;
        int c1 = rand() % SIZE;
        int r2 = rand() % SIZE;
        int c2 = rand() % SIZE;

        char temp = board[r1][c1];
        board[r1][c1] = board[r2][c2];
        board[r2][c2] = temp;
    }
}

// Print the board showing revealed and hidden cards
void printBoard() {
    printf("\nBoard:\n");
    printf("   ");
    for (int i = 0; i < SIZE; i++) printf("%d ", i);
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j])
                printf("%c ", board[i][j]);
            else
                printf("* ");
        }
        printf("\n");
    }
}

// Let the player play one turn
void playTurn() {
    int r1, c1, r2, c2;

    // First card
    printf("Enter coordinates for first card (row col): ");
    scanf("%d %d", &r1, &c1);
    while (revealed[r1][c1]) {
        printf("Already revealed. Choose again: ");
        scanf("%d %d", &r1, &c1);
    }
    revealed[r1][c1] = 1;
    printBoard();

    // Second card
    printf("Enter coordinates for second card (row col): ");
    scanf("%d %d", &r2, &c2);
    while (revealed[r2][c2] || (r1 == r2 && c1 == c2)) {
        printf("Invalid choice. Choose again: ");
        scanf("%d %d", &r2, &c2);
    }
    revealed[r2][c2] = 1;
    printBoard();

    // Check match
    if (board[r1][c1] == board[r2][c2]) {
        printf("It's a match!\n");
    } else {
        printf("Not a match.\n");
        revealed[r1][c1] = 0;
        revealed[r2][c2] = 0;
    }
}

// Check if the game is over
int isGameOver() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (!revealed[i][j])
                return 0;
    return 1;
}
