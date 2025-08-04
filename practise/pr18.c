#include <stdio.h>

// Step 1: Define a function that calculates the area of a rectangle
// The function should take two integer parameters: length and width
int calculateArea(int length, int width) {
    // Step 2: Return the product of length and width
    return length * width;  // Replace 0 with the correct operation
}

int main() {
    int length, width;

    // Step 3: Ask the user to enter the length and width of the rectangle
    printf("Enter the length of the rectangle: ");
    // Use scanf to accept the length
    scanf("%d", &length);
    printf("Enter the width of the rectangle: ");
    // Use scanf to accept the width
    scanf("%d", &width);

    // Step 4: Call the calculateArea() function with the user inputs
    // Store the result in a variable (area)

    // Step 5: Print the calculated area using printf
    int area = calculateArea(length, width);
    printf("The area of the rectangle is: %d\n", area);

    return 0;
}
