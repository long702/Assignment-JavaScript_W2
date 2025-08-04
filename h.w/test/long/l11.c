#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 4  // 4x4 grid
#define TOTAL_PAIRS 8

typedef struct {
    char symbol;
    int flipped;  // 0 = face down, 1 = face up
} Card;

Card board[SIZE][SIZE];

// Function declarations
void initializeBoard();
void shuffleBoard();
void displayBoard();
void playTurn();
int isGameOver();
void clearScreen();

int main() {
    srand(time(NULL));
    initializeBoard();
    shuffleBoard();

    printf("=== MEMORY MATCHING GAME ===\n");

    while (!isGameOver()) {
        displayBoard();
        playTurn();
    }

    displayBoard();
    printf("🎉 Congratulations! You found all the pairs!\n");
    return 0;
}

// Initialize board with pairs of symbols
void initializeBoard() {
    char symbols[TOTAL_PAIRS * 2] = {
        'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D',
        'E', 'E', 'F', 'F', 'G', 'G', 'H', 'H'
    };

    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j].symbol = symbols[index++];
            board[i][j].flipped = 0;
        }
    }
}

// Shuffle the board
void shuffleBoard() {
    for (int i = 0; i < SIZE * SIZE; i++) {
        int r1 = rand() % SIZE;
        int c1 = rand() % SIZE;
        int r2 = rand() % SIZE;
        int c2 = rand() % SIZE;

        Card temp = board[r1][c1];
        board[r1][c1] = board[r2][c2];
        board[r2][c2] = temp;
    }
}

// Display the board
void displayBoard() {
    printf("\n    ");
    for (int j = 0; j < SIZE; j++) {
        printf(" %d ", j);
    }
    printf("\n   -----------------\n");

    for (int i = 0; i < SIZE; i++) {
        printf(" %d |", i);
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j].flipped)
                printf(" %c ", board[i][j].symbol);
            else
                printf(" * ");
        }
        printf("|\n");
    }
    printf("   -----------------\n");
}

// Play one turn: choose two cards and check for match
void playTurn() {
    int r1, c1, r2, c2;

    // First selection
    printf("Choose first card (row col): ");
    scanf("%d %d", &r1, &c1);
    while (r1 < 0 || r1 >= SIZE || c1 < 0 || c1 >= SIZE || board[r1][c1].flipped) {
        printf("Invalid or already flipped. Choose again: ");
        scanf("%d %d", &r1, &c1);
    }
    board[r1][c1].flipped = 1;
    displayBoard();

    // Second selection
    printf("Choose second card (row col): ");
    scanf("%d %d", &r2, &c2);
    while (r2 < 0 || r2 >= SIZE || c2 < 0 || c2 >= SIZE || board[r2][c2].flipped || (r1 == r2 && c1 == c2)) {
        printf("Invalid or already flipped. Choose again: ");
        scanf("%d %d", &r2, &c2);
    }
    board[r2][c2].flipped = 1;
    displayBoard();

    // Check for match
    if (board[r1][c1].symbol == board[r2][c2].symbol) {
        printf("✅ Match found!\n");
    } else {
        printf("❌ Not a match. Cards will be flipped back.\n");
        // Delay before hiding cards again
        printf("Press Enter to continue...");
        getchar(); getchar(); // wait for Enter
        board[r1][c1].flipped = 0;
        board[r2][c2].flipped = 0;
    }
}

// Check if all cards are flipped (game over)
int isGameOver() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (!board[i][j].flipped)
                return 0;
    return 1;
}
