#include <stdio.h>

// Function to swap two integers using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10;
    int y = 20;

    // Print values and addresses before swap
    printf("Before the swap:\n");
    printf("X = %d\t(address %p)\n", x, (void*)&x);
    printf("Y = %d\t(address %p)\n", y, (void*)&y);

    // Call the swap function
    swap(&x, &y);

    // Print values and addresses after swap
    printf("\nAfter the swap:\n");
    printf("X = %d\t(address %p)\n", x, (void*)&x);
    printf("Y = %d\t(address %p)\n", y, (void*)&y);

    return 0;
}
