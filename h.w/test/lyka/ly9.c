#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char* name;
    int age;
} Person;

int main() {
    Person* person = (Person * )malloc(sizeof(Person));

    if(Person == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }
    Person->name = (char *)malloc(100 * sizeof(char));
    if(Person->name == NULL){
        printf("Memory allocation failed!\n");
        free(Person);
        return 1;
    }

    strcpy(Person->name, "Alice");
    Person->age = 20;

    printf("Name: %s\n", Person->name);
    printf("Age: %d\n", Person->age);

    free(Person->name);
    free(person);  

    return 0;
}


