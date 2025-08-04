#include <stdio.h>

#define SIZE 5

// Function prototypes
int canMove(char grid[SIZE][SIZE], int x, int y, char direction);
void moveCaptain(char grid[SIZE][SIZE], int *x, int *y, char direction);
void printGrid(char grid[SIZE][SIZE]);

int main() {
    char grid[5][5] = {
        {'0', '0', '0', '0', '0'},
        {'0', 'c', 'w', '0', '0'},
        {'0', '0', 'w', '0', '0'},
        {'0', '0', 'W', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    int x = 2, y = 2; // Captain starts at (2, 2)

    printGrid(grid);

    // Try moving
    moveCaptain(grid, &x, &y, 'L');  // Left
    moveCaptain(grid, &x, &y, 'U');  // Up
    moveCaptain(grid, &x, &y, 'R');  // Right

    printGrid(grid);

    return 0;
}

// Check if move is valid
int canMove(char grid[SIZE][SIZE], int x, int y, char direction) {
    int newX = x, newY = y;

    switch (direction) {
        case 'U': newX--; break;
        case 'D': newX++; break;
        case 'L': newY--; break;
        case 'R': newY++; break;
        default: return 0;
    }

    // Check boundaries
    if (newX < 0 || newX >= SIZE || newY < 0 || newY >= SIZE)
        return 0;

    // Check wall
    if (grid[newX][newY] == 'W')
        return 0;

    return 1;
}

// Move the captain if possible
void moveCaptain(char grid[SIZE][SIZE], int *x, int *y, char direction) {
    if (canMove(grid, *x, *y, direction)) {
        int newX = *x, newY = *y;

        switch (direction) {
            case 'U': newX--; break;
            case 'D': newX++; break;
            case 'L': newY--; break;
            case 'R': newY++; break;
        }

        grid[*x][*y] = '0';          // Clear old position
        grid[newX][newY] = 'C';      // Move captain
        *x = newX;
        *y = newY;
    } else {
        printf("Move blocked by wall or boundary.\n");
    }
}

// Print the grid
void printGrid(char grid[SIZE][SIZE]) {
    printf("\nGrid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}
