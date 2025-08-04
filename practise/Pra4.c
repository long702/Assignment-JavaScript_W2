#include <stdio.h>

void addBonus(int grades[], int size, int bonus) {
    for (int i = 0; i < size; i++) {
        grades[i] += bonus;
        if (grades[i] > 20) {
            grades[i] = 20;
        }
    }
}
int main() {
    int grades[] = {9, 8, 19, 13, 15};
    int size = 5;
    int bonus = 2;

    addBonus(grades, size, bonus);

    // Print updated grades
    for (int i = 0; i < size; i++) {
        printf("%d ", grades[i]);
    }

    return 0;
}










