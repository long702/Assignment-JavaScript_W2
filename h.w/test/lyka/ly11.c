#include <string.h>
#include <stdio.h>

#define MAX_LEN 100

typedef struct {
    char data[MAX_LEN];
} String;

String substring(String src, int start, int end) {
    String result;
    int length = end - start + 1;  // Calculate the length of the substring
    
    // Copy characters from src.data[start] to src.data[end] into result.data
    strncpy(result.data, &src.data[start], length);
    
    // Null-terminate the string
    result.data[length] = '\0';
    
    return result;
}
int main() {
    String s1, s2, s3;
    strcpy(s1.data, "hamburger");
    strcpy(s2.data, "international");
    strcpy(s3.data, "celebration");
    
    String result1 = substring(s1, 4, 8);
    String result2 = substring(s2, 0, 4);
    String result3 = substring(s3, 3, 6);
    
    printf("Substring 1: %s\n", result1.data);  
    printf("Substring 2: %s\n", result2.data);  
    printf("Substring 3: %s\n", result3.data);
    
    return 0;
}