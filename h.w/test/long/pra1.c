#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    int** seating_chart = NULL;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0) {
        printf("Error: Rows and columns must be positive numbers.\n");
        return 1;
    }

    seating_chart = (int**)malloc(rows * sizeof(int*));
    if (seating_chart == NULL) {
        printf("Error: Memory allocation failed for row pointers.\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        seating_chart[i] = (int*)malloc(cols * sizeof(int));
        if (seating_chart[i] == NULL) {
            printf("Error: Memory allocation failed for row %d.\n", i);
            
            for (int j = 0; j < i; j++) {
                free(seating_chart[j]);
            }
            free(seating_chart);
            return 1;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter student ID at row %d, column %d: ", i, j);
            scanf("%d", &seating_chart[i][j]);
        }
    }

    printf("\nSeating Chart:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", seating_chart[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(seating_chart[i]);
    }
    free(seating_chart);

    return 0;
}