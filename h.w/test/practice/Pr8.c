#include <stdio.h>

int countA(char text[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (text[i] == 'a') {
            count++;
        }
    }
    return count;
}

int main() {
    char text1[4] = {'a', 'b', 'b', 'a'};
    char text2[5] = {'b', 'a', 'a', 't', 't'};
    char text3[6] = {'r', 'w', 'q', 'q', 'i', 'a'};

    printf("Number of 'a' in text1: %d\n", countA(text1, 4));
    printf("Number of 'a' in text2: %d\n", countA(text2, 5));
    printf("Number of 'a' in text3: %d\n", countA(text3, 6));

    return 0;
}
