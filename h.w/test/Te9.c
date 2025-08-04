#include <stdio.h> 
    void print_arrays(int row, int col, int arr[row][col]);
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                printf("%d", array[i][j]);
            }
            printf("\n");
        }
int main() {
    int array1[3][3] = {
                        {1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}
                    };

    int array2[3][3] = {
                        {3, 2, 3},
                        {4, 1, 6},
                        {5, 7, 11}
                    };
    void sum2D(int row, int col, int array1[row][col], int array2[row][col]);
    int sumarray[row][col];
    printf("The sum of 2 array: \n");
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                sumarray[i][j] = array1[i][j] + array2[i][j];
                   printf("%f",array[i][j]);
            }
            printf("\n");
        }
    }
    void sub2D(int row, int col, int array1[row][col], int array2[row][col]);
    int subarray[row][col];
    printf("The sub of 2 array: \n");
       for (int i = 0; i < 3; i++){
           for (int j = 0; j < 3; j++){
            sumarray[i][j] = array1[i][j] - array2[i][j];
            printf("%f", array[i][j]);
            }
        
    printf("\n"result);
return 0;
}
    

