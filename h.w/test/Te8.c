#include <stdio.h>
#include <stdbool.h>

#define N 5
#define MAGIC_SUM 65

bool isMagicSquare(int size, int grid[N][N]) {
    // 1. Check if all numbers from 1 to 25 appear exactly once
    bool seen[26] = {false};  // index 0 is unused

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num = grid[i][j];
            if (num < 1 || num > 25 || seen[num]) {
                return false;  // Invalid number or duplicate
            }
            seen[num] = true;
        }
    }

    // 2. Check rows sum to MAGIC_SUM
    for (int i = 0; i < N; i++) {
        int rowSum = 0;
        for (int j = 0; j < N; j++) {
            rowSum += grid[i][j];
        }
        if (rowSum != MAGIC_SUM) return false;
    }

    // 3. Check columns sum to MAGIC_SUM
    for (int j = 0; j < N; j++) {
        int colSum = 0;
        for (int i = 0; i < N; i++) {
            colSum += grid[i][j];
        }
        if (colSum != MAGIC_SUM) return false;
    }

    // 4. Check both diagonals
    int diag1 = 0, diag2 = 0;
    for (int i = 0; i < N; i++) {
        diag1 += grid[i][i];             // Top-left to bottom-right
        diag2 += grid[i][N - 1 - i];     // Top-right to bottom-left
    }
    if (diag1 != MAGIC_SUM || diag2 != MAGIC_SUM) return false;

    return true;
}

int main() {
    int square[N][N] = {
        {17, 24, 1, 8, 15},
        {23, 5, 7, 14, 16},
        {4, 6, 13, 20, 22},
        {10, 12, 19, 21,3},
        {11, 18, 25, 2, 9}
    };

    if (isMagicSquare(N, square)) {
        printf("Valid magic square!\n");
    } else {
        printf("Not a valid magic square.\n");
    }

    return 0;
}



        
    

    
