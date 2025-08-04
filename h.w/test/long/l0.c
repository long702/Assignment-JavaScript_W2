#include<stdio.h>
int main(){
    int arr[3][3] = {
                  {23, 12, 56},
                  {12, 15, 32},
                  {35, 37, 52},
                };
                  
    // find Maximum in 1D Array
    int row =0;
    int col = 0;
    int rowsum = 0;
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
                rowSum += arr[i][j];
                printf("%d   ", rowsum);
        }else{
            printf("");
        }
    }
        printf("\n");

    return 0;
}
    

