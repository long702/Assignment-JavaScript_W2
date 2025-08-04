#include<stdio.h>
#include<stdbool.h>
#define GAME_SIZE 5 // Game row and columns
#define WIN_COUNT 5 // Game row and columns

#define PLAYER_1_SYMBOL 'X'
#define PLAYER_2_SYMBOL 'O'

#define PLAYER_1_WON 1
#define PLAYER_2_WON 2
#define DRAW_GAME 3

char mat[5][5] = {
        {'.','.','.','.','.'},
        {'.','.','.','.','.'},
        {'.','.','.','.','.'},
        {'.','.','.','.','.'},
        {'.','.','.','.','.'}
    };

void print_arr(){
    for(int i = 0; i < GAME_SIZE; i++){
        for(int j = 0; j < GAME_SIZE; j++){
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
}

void intro(){
    printf("#########################################\n");
    printf("##   Welcome to our Tic Tac Toe Game.  ##\n");
    printf("#########################################\n");
    print_arr();
    printf("In order to play this game you have to read this introduction.\n");
    printf("!!Your position have to be difference from other players!!\n");
    printf("When the user enters row 0 and column 0,\nit refers to the top-left corner the very first position on the board.\n");
    printf("The result will be 1(player 1 win) ,2(player 2 win) and 3(Draw) ");
    printf("Here is our board \n");
}

bool isValidMove(int row, int col){
    bool result = (row >= 0 && row < GAME_SIZE && col >= 0 && col < GAME_SIZE);
    return result;
}

int checkGame() {
    int x, o;
    for (int i = 0; i < GAME_SIZE; i++) {
        x = 0;
        o = 0;
        for (int j = 0; j < GAME_SIZE; j++) {
            if (mat[i][j] == PLAYER_1_SYMBOL) {
                x++;
            } else if (mat[i][j] == PLAYER_2_SYMBOL) {
                o++;
            }
        }
        if (x == WIN_COUNT) {
            return PLAYER_1_WON;
        } else if (o == WIN_COUNT) {
            return PLAYER_2_WON;
        }
    }

    for (int j = 0; j < GAME_SIZE; j++) {
        x = 0;
        o = 0;
        for (int i = 0; i < GAME_SIZE; i++) {
            if (mat[i][j] == PLAYER_1_SYMBOL) {
                x++;
            } else if (mat[i][j] == PLAYER_2_SYMBOL) {
                o++;
            }
        }
        if (x == WIN_COUNT) {
            return PLAYER_1_WON;
        } else if (o == WIN_COUNT) {
            return PLAYER_2_WON;
        }
    }
    x = 0;
    o = 0;
    for (int i = 0; i < GAME_SIZE; i++) {
        if (mat[i][i] == PLAYER_1_SYMBOL) {
            x++;
        } else if (mat[i][i] == PLAYER_2_SYMBOL) {
            o++;
        }
    }
    if (x == WIN_COUNT) {
        return PLAYER_1_WON;
    } else if (o == WIN_COUNT) {
        return PLAYER_2_WON;
    }
    x = 0;
    o = 0;
    for (int i = 0; i < GAME_SIZE; i++) {
        if (mat[i][GAME_SIZE - 1 - i] == PLAYER_1_SYMBOL) {
            x++;
        } else if (mat[i][GAME_SIZE - 1 - i] == PLAYER_2_SYMBOL) {
            o++;
        }
    }
    if (x == WIN_COUNT) {
        return PLAYER_1_WON;
    } else if (o == WIN_COUNT) {
        return PLAYER_2_WON;
    }
    for (int i = 0; i < GAME_SIZE; i++){
        for (int j = 0; j < GAME_SIZE; j++){
            if (mat[i][j] == '.') {
                return 0; 
            }
        }
    }

    return DRAW_GAME;
}

void makeMove(){
    int row;
    int col;
    int status = 0;

    while(true){
        print_arr();

        printf("Player 1: (Row Col): ");
        scanf("%d %d", &row, &col);

        if(!isValidMove(row, col)){
            printf("Invalid move. Try again.\n");
            continue;
        }
        if(mat[row][col] != '.') {
            printf("Cell already taken.\n");
            continue;
        }
        mat[row][col] = PLAYER_1_SYMBOL;

        status = checkGame();
        if(status == PLAYER_1_WON) {
            print_arr();
            printf("Player 1 Wins!\n");
            break;
        }
        if(status == DRAW_GAME) {
            print_arr();
            printf("Game Draw!\n");
            break;
        }

        print_arr();

        printf("Player 2: (Row Col): ");
        scanf("%d %d", &row, &col);
if(!isValidMove(row, col)){
            printf("Invalid move. Try again.\n");
            continue;
        }
        if(mat[row][col] != '.') {
            printf("Cell already taken.\n");
            continue;
        }
        mat[row][col] = PLAYER_2_SYMBOL;

        status = checkGame();
        if(status == PLAYER_2_WON) {
            print_arr();
            printf("Player 2 Wins!\n");
            break;
        }
        if(status == DRAW_GAME) {
            print_arr();
            printf("Game Draw!\n");
            break;
        }
    }
}

int main() {
    intro();
    makeMove();
    return 0;
}