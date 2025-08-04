#include <stdio.h>
#include <ctype.h>

void toUpper(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = toupper((unsigned char)str[i]);
        i++;
    }
}

int main() {
    char text[] = "Ronan is The Best!";
    toUpper(text);
    printf("%s\n", text);  
    return 0;
}
