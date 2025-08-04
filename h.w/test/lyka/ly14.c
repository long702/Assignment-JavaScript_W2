#include <stdio.h>
  int main(){
    int numbers[5];
    int sum = 0;
    printf("Enter 5 integers:\n");
    for (int i = 0; i < 5; i++){
        printf("Numbers %d: ", i+1);
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }
    printf("The numbers you entered are:\n");
    for (int i = 0; i <5; i++){
        printf("%d", numbers[i]);
    }
    printf("\nThe sum of all numbers is: %d\n", sum);

    return 0;
  }