#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int salary;
} Employee;

int main() {
    Employee* employees = NULL;
    int initial_size = 2;
    int expanded_size = 5;
    
    employees = (Employee*)malloc(initial_size * sizeof(Employee));
    if (employees == NULL) {
        printf("Error: Memory allocation failed for initial employees.\n");
        return 1;
    }
    
    printf("Enter details for first 2 employees:\n");
    for (int i = 0; i < initial_size; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Name: ");
        scanf("%49s", employees[i].name); 
        printf("Salary: ");
        scanf("%d", &employees[i].salary);
    }
    
    Employee* temp = (Employee*)realloc(employees, expanded_size * sizeof(Employee));
    if (temp == NULL) {
        printf("Error: Memory reallocation failed.\n");
        free(employees); 
        return 1;
    }
    employees = temp;
    printf("\nEnter details for remaining 3 employees:\n");
    for (int i = initial_size; i < expanded_size; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Name: ");
        scanf("%49s", employees[i].name);
        printf("Salary: ");
        scanf("%d", &employees[i].salary);
    }
    printf("\nEmployee List:\n");
    printf("-------------------------------------\n");
    printf("%-20s %-10s\n", "Name", "Salary");
    printf("-------------------------------------\n");
    for (int i = 0; i < expanded_size; i++) {
        printf("%-20s $%-10d\n", employees[i].name, employees[i].salary);
    }
    printf("--------------------------------------\n");
    
    free(employees);
    employees = NULL;
    
    return 0;
}