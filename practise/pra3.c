#include <stdio.h>
int main(){
    float matrix[3][3]= 
                {{11, 12.5, 13.2},
                 {2.1, 2.2, 2.3},
                 {3, 3.1, 3.3}
                };
    for (int i = 0; i <3; i++){
        for (int j = 0; j <3; j++){
            printf("%.1f ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}

