#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

typedef struct{
    char data[MAX_LEN];
} string;

string substring(string src, int start, int end){
    string result;
    int length = end - start +1;
    strncpy(result.data, &src.data[start], length);
    result.data[length] = '\0';
    return result;
}
int main(){
    string s1, s2, s3;
    strcpy(s1.data, "hamburger");
    strcpy(s2.data, "international");
    strcpy(s3.data, "celebration");

    string result1 = substring(s1, 4, 8);
    string result2 = substring(s2, 0, 4);
    string result3 = substring(s3, 3, 6);

    printf("Substring 1: %s\n", result1.data);
    printf("Substring 2: %s\n", result2.data);
    printf("Substring 3: %s\n", result3.data);

    return 0;
}
