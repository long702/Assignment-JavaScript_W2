#include <stdio.h>

int compute_sum(int arr[], int size) {
    int sum = 0;
    for (int i = 1; i <= size; i++) {   
        sum += arr[i];
    }
    return sum;
}

int main() {
    int numbers[6] = {1, 2, 4, 6, 8, 10,};
    int total = compute_sum(numbers, 5);
    printf("The total is: %d\n", total);
    return 0;
}

