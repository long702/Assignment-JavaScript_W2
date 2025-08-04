#include <stdio.h>

void checkArrays(int array[3][3], int array1[3][3], int array2[3][3]) {
    int i, j;
    int rowarray1; int rowarray2;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (array1[i][j] + array2[i][j]) {
                sumarray = rowarray1[i] + rowarray2[i];
                printf("%d\n", array[i]);
                return;
            }
        }
    }
    printf("\n");
}

int main() {
    int array[3][3];
    int array1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int array2[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    checkArrays(array, array1, array2);

    return 0;
}
