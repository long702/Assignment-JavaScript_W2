#include<stdio.h>
#include<stdbool.h>
void intro(){
    printf("In order to play this game you can follow this instruction!\n");
    printf("1. W : go up.\n");
    printf("2. S : go down.\n") ;       
    printf("3. A : go left.\n");        
    printf("4. D : go right.\n");
}

int row = 0;
int col = 0;

void found_C(char mat[5][5]){
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            if(mat[i][j] == 'C'){
                row = i;
                col = j;
                
            }
        }
    } 
}
bool moveCaptain(char mat[5][5], char dir){
    if (dir == 'W' && row>0){
        mat[row-1][col] = 'C';
        mat[row][col] = '0';
        return true;
    }else if (dir == 'S' && row<4){
        mat[row+1][col] = 'C';
        mat[row][col] = '0';
        return true;
    }else if(dir == 'A' && col > 0){
        mat[row][col-1] = 'C';
        mat[row][col] = '0';
        return true;
    }else if (dir == 'D' && col < 5){
        mat[row][col+1] = 'C';
        mat[row][col] = '0';
        return true;
    }


    return false;
}

int main(){
    intro();
    char matrix[5][5] = {
        {'0', '0', '0', '0', '0'},
        {'0', 'c', 'w', '0', '0'},
        {'0', '0', 'w', '0', '0'},
        {'0', '0', 'w', '0', '0'},
        {'0', '0', '0', '0', '0'},
    };
    char mov;
        printf("Move by (W,S,A,D) :");
        scanf(" %c",&mov);
        moveCaptain(matrix,mov );
        
        for (int i = 0; i<5; i++){
            for(int j = 0; j<5; j++){
                printf("%c  ",matrix[i][j]);
            }
            printf("\n");
            }
    return 0;
}