#include <stdio.h>

// Helper function: returns 1 if characters are equal, 0 otherwise
int charEquals(char a, char b) {
    return a == b;
}

// Main function: mimics strcmp()
int my_strcmp(const char *s1, const char *s2) {
    int i = 0;

    // Compare characters one by one
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (!charEquals(s1[i], s2[i])) {
            return s1[i] - s2[i];  // Return lexicographical difference
        }
        i++;
    }

    // If we reached the end of one or both strings
    return s1[i] - s2[i];  // Also handles empty or length mismatch cases
}

int main() {
    printf("%d\n", my_strcmp("apple", "apple"));     // 0
    printf("%d\n", my_strcmp("apple", "apricot"));   // negative
    printf("%d\n", my_strcmp("banana", "apple"));    // positive
    printf("%d\n", my_strcmp("", ""));               // 0
    printf("%d\n", my_strcmp("a", ""));              // positive
    printf("%d\n", my_strcmp("", "a"));              // negative
    
    return 0;
}
