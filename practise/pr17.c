#include <stdio.h>

int main() {
    char grade;

    // Step 1: Ask the user to input a letter grade (A, B, C, D, F)
    // Use the scanf() function to capture the user input.

    // Step 2: Use a switch statement to compare the input grade.
    // Depending on the input, print the corresponding message:
    // - 'A': "Excellent!"
    // - 'B': "Good"
    // - 'C': "Average"
    // - 'D': "Below Average"
    // - 'F': "Fail"

    // Step 3: Add a default case to handle invalid grades
    // If the input is not A, B, C, D, or F, print "Invalid grade."
    printf("Enter your grade(A, B, C, D, F): ");
    
    scanf("%c", &grade);

    switch (grade){
        case 'A':
           printf("A: Excellent!\n");
           break;
        case 'B':
           printf("B:  Good\n");
           break;
        case 'C':
           printf("C: Average\n");
           break;
        case 'D':
           printf("D: Below Average\n");
           break;
        case 'F':
           printf("F: Fail\n");
           break;
        default:
           printf("Invalid grade! ");
           
        
    }

    return 0;


}