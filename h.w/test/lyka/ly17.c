#include <stdio.h>

// Function prototypes
void inputArray(int arr[], int size);          
void printArray(int arr[], int size);         
int sumArray(int arr[], int size);             

int main() {
    int numbers[5];
    int total;

    // Input array elements
    inputArray(numbers, 5);

    // Print the array
    printf("The numbers you entered are:\n");
    printArray(numbers, 5);

    // Calculate and print the sum
    total = sumArray(numbers, 5);
    printf("The sum of all numbers is: %d\n", total);

    return 0;
}

// Function to input array elements
void inputArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Function to print array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to calculate and return sum of array
int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}
