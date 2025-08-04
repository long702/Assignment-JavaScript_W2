
   #include <stdio.h>

int lengthOf(const char* str) {
    int count = 0;
    
    
    while (str[count] != '\0') {
        count++;
    }
    
    return count;
}
int main() {
    const char* testString = "abcd";
    int size = lengthOf(testString);
    printf("size: %d\n", size);  
    return 0;
}


 
   
