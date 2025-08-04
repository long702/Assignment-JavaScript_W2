#include <stdio.h>

int computeAverage(int grades[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += grades[i];
    }

    return sum / size; // Integer division automatically truncates (rounds down)
}
    int main() {
    int grades1[] = {10, 12, 10, 12};
    int size1 = 4;
    printf("Average: %d\n", computeAverage(grades1, size1)); // Output: 11

    int grades2[] = {20, 20, 20};
    int size2 = 3;
    printf("Average: %d\n", computeAverage(grades2, size2)); // Output: 20

    return 0;
}







