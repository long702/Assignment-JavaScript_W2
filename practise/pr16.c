#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;      
    int size;       
    int capacity;   
} List;

void addToList(List* theList, int item) {
    if (theList->size == theList->capacity) {
        int new_capacity = theList->capacity + 2;
        int* temp = realloc(theList->data, new_capacity * sizeof(int));
        
        if (temp == NULL) {
            printf("Memory reallocation failed\n");
            return;
        }
        
        theList->data = temp;
        theList->capacity = new_capacity;
        printf("--> List is full, resizing to %d\n", new_capacity);
    }
    theList->data[theList->size] = item;
    theList->size++;
}

int main() {
    List myList;  
    myList.size = 0;
    myList.capacity = 2;
    myList.data = malloc(myList.capacity * sizeof(int));
    if (myList.data == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    printf("Adding items to the list:\n");
    for (int i = 0; i < 5; i++) {
        int value = (i + 1) * 10;
        printf("Adding item: %d\n", value);
        addToList(&myList, value);
    }

    printf("\nFinal list contents (%d items):\n", myList.size);
    for (int j = 0; j < myList.size; j++) {
        printf("%d ", myList.data[j]);
    }
    printf("\n");

    free(myList.data);
    myList.data = NULL;

    return 0;
}