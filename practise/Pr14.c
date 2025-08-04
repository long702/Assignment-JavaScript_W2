#include <stdio.h>
   int main(){
    int i,j,k = 0;
    int row;
    int space = 0;
    int blank[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
    k = 0;
    int b[4] = {0,1,2,3};
    int z = 0;
    char character, temp;
    printf("input character :");
    scanf("%c",&temp);
    fflush (stdin);
    printf("input rows :");
    scanf("%d", &row);
    for (int i = 0; i < row; i++){
        printf("\n");
        character = temp;
        space = blank[k++];
        for (int j = 0; j < space; j++){
            printf(" ");
        }
        for (int j = space-1; j < row-1; j++){
            printf("%c", character++);
        }
        character = character-2;
        for (int j = row-1; j > i; j--){

        }
    }
    return 0;
}
  