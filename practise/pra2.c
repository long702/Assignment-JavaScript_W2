#include <stdio.h>

int parseInt(const char* str) {
    int result = 0;
    int i = 0;

    while (str[i] != '\0') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result;
}

int main() {
    printf("%d\n", parseInt("0"));        
    printf("%d\n", parseInt("1597"));     
    printf("%d\n", parseInt("123456"));  
    return 0;
}
