#include <stdio.h>
#include <stdbool.h>
#define N 5
#define MAGIC_SUM 65
   int main(){
    int Square[N][N] = {
        {17, 24, 1, 8, 15},
        {23, 5, 7, 14, 16},
        {4, 6, 13, 20, 22},
        {10, 12, 19 , 21, 3},
        {11, 18, 25, 2, 9},};
    for(int row = 0; row <5; row++){
        int sumrow =0;
        for(int column = 0; column<5; column++){
            sumrow+= Square[row][column];
        }printf("%d\n  ",sumrow);
         }

    }
         bool isMagicSquare(int size, int grid[N][N]) {
    int sum;

    // Check all numbers from 1 to 25 appear exactly once
    bool seen[N * N + 1] = {false};  // index 1 to 25

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num = grid[i][j];
            if (num < 1 || num > N * N || seen[num]) {
                return false;
            }
            seen[num] = true;
        }
    }

    // Check row sums
    for (int i = 0; i < N; i++) {
        sum = 0;
        for (int j = 0; j < N; j++) {
            sum += grid[i][j];
        }
        if (sum != MAGIC_SUM) return false;
    }

    // Check column sums
    for (int j = 0; j < N; j++) {
        sum = 0;
        for (int i = 0; i < N; i++) {
            sum += grid[i][j];
        }
        if (sum != MAGIC_SUM) return false;
    }

    // Check main diagonal (top-left to bottom-right)
    sum = 0;
    for (int i = 0; i < N; i++) {
        sum += grid[i][i];
    }
    if (sum != MAGIC_SUM) return false;

    // Check secondary diagonal (top-right to bottom-left)
    sum = 0;
    for (int i = 0; i < N; i++) {
        sum += grid[i][N - 1 - i];
    }
    if (sum != MAGIC_SUM) return false;

    return true;
}


    