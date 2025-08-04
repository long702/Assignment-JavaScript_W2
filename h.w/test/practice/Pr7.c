#include <stdio.h>

int main() {
    int assignments[3] = {15, 10, 18};
    int exams[3] = {40, 50, 32};
    float averages[3];

    for (int i = 0; i < 3; i++) {
        averages[i] = (assignments[i] + exams[i]) / 2.0;
        printf("Student %d average: %.2f\n", i + 1, averages[i]);
    }

    return 0;
}