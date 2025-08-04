
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char *name;
    int age;
} Person;

int main() {
    Person *person = (Person *)malloc(sizeof(Person));
    if (person == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    person->name = (char *)malloc(100 * sizeof(char)); 
    if (person->name == NULL) {
        printf("Memory allocation for name failed!\n");
        free(person); 
        return 1;
    }
    strcpy(person->name, "Alice "); 
    person->age = 20;

    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);

    free(person->name);
    free(person);

      return 0;
    
}


