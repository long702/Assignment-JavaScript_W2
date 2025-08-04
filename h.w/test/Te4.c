#include <stdio.h>

int total = 100; 

void printScore(int score) {
    int bonus = 5;
    if (score > 50) {
        int total = score + bonus;
        printf("The total = %d\n", total);  // Point A
    }
    printf("The bonus = %d\n", bonus);  // Point B 
}

int main() {
    int score = 80;
        Process(score);
    
        return 0; // Point C
}
