#include <stdio.h>

int lengthOf(const char* str) {
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}

int main() {
    char name[100];  

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    int len = lengthOf(name);
    if (name[len - 1] == '\n') {
        name[len - 1] = '\0';  
    }

    int nameLength = lengthOf(name);
    printf("Your name has %d characters\n", nameLength);

    return 0;
}
