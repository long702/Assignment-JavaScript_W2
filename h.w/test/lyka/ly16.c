#include <stdio.h>
   int main(){
      int number, sum = 0;
      printf("Enter numbers to sum (0 to stop):\n");

      do {
        printf("Enter number:");
        scanf("%d", &number);
        sum += number;
      }while (number != 0);
      printf("Total sum is: %d\n", sum);

      return 0;
   }