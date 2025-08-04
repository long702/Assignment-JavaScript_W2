#include <stdio.h>
  int main(){
    int matrix[2][3];
    int sum = 0;
     
    printf("Enter 6 elements for 2x3 matrix:\n");
    for (int i = 0; i < 2; i++){
        for ( int j = 0; j < 3; j++){
        printf("Element [%d][%d]:", i,j);
        scanf("%d", &matrix[i][j]);
        sum += matrix[i][j];
        }
    }
    printf("Matrix is:\n");
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("Sum of all elements: %d\n", sum);


    return 0;


  }