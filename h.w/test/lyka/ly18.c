#include <stdio.h>

// Function prototypes
void inputMatrix(int matrix[2][3]);          
void printMatrix(int matrix[2][3]);          
int sumMatrix(int matrix[2][3]);             

int main() {
    int matrix[2][3];
    int total;

    // Input matrix
    inputMatrix(matrix);

    // Display matrix
    printf("Matrix is:\n");
    printMatrix(matrix);

    // Calculate and display sum
    total = sumMatrix(matrix);
    printf("Sum of all elements: %d\n", total);

    return 0;
}

// Function to input elements into 2x3 matrix
void inputMatrix(int matrix[2][3]) {
    printf("Enter 6 elements for 2x3 matrix:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print 2x3 matrix
void printMatrix(int matrix[2][3]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate and return the sum of matrix elements
int sumMatrix(int matrix[2][3]) {
    int sum = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}
