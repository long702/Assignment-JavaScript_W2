#include <stdio.h>
  int main(){
    int n,i,j,k;
    printf("odd number :");
    scanf("%d",&n);
    for (int i =0; i <= n/2; i++){
        for (int j = 0; j < (n/2)-i; j++){
            printf("");
        }
        for (int k = 0; k < (2*i)+1; k++){
            if (k < i){
                printf("*");
            }else{
                printf("#");
            }
        }
        printf("\n");
    }
    for ( i = 0; i < n/2; i++){
        for (j = 0; j < i+1; j++){
            printf("");
        }
    }
    return 0;
  }