#include <stdio.h>
// Function to log array elements and their memory addresses
void log(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Element %d = %d\t(Address = %p)\n", i, *(arr + i), (void*)(arr + i));
    }
}

int main() {
    int data[] = {10, 20, 30, 40, 50};
    int size = sizeof(data) / sizeof(data[0]);

    // Call the log function
    log(data, size);

    return 0;
}

    