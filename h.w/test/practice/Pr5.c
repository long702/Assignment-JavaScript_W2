#include <stdio.h>

int main() {
  int matrix[3][3] = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9},
  };
 

  for (int column = 0; column < 3; column++) {
    int sumcolumn =0;
    for (int row = 0; row < 3; row++) {
      sumcolumn+=matrix[row][column];
    }
    printf("%d - ", sumcolumn);
  }
  return 0;
}
