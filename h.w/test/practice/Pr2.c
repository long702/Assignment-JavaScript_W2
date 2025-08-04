#include <stdio.h>

int counter = 0;  

void increment() {
    int counter = 10;  
    counter++;
    printf("Inside function: counter = %d\n", counter);  // Point A
}

int main() {
    printf("Before function call: counter = %d\n", counter);
    increment();  // Point B
    printf("After function call: counter = %d\n", counter);  // Point C
    return 0;
}
