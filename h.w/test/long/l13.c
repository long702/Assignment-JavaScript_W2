#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 5
struct Student{
    int id;
    char name[50];
    float GPA;
};
void inputStudent(struct Student *s){
    //your code here
    printf("Enter the student ID: ");
    scanf("%d", &s->id);
    getchar();
    printf("Enter student name:");
    scanf("%[^\n]", s->name);
    printf("Enter GPA:");
    scanf("%f", &s->GPA);

}
void displayStudent(const struct Student *s){
    printf("ID: %d | name: %s | GPA: %.2f\n", s->id, s->name, s->GPA);
}
float calculateAverageGPA(struct Student students[], int numStudents){
    float sum = 0.0;
    for (int i = 0; i < numStudents; i++){
        sum += students[i].GPA;
    }
   return sum / numStudents;
}
int main() {
struct Student class[MAX_STUDENTS];
int numStudents;
    printf("Enter the number of students (max %d): ", MAX_STUDENTS);
    scanf("%d", &numStudents);
if (numStudents > MAX_STUDENTS || numStudents <= 0) {
    printf("Invalid number of students.\n");
    return 1;
}
printf("\n--- Enter Student Details ---\n");
for (int i = 0; i < numStudents; i++) {
    printf("Student %d:\n", i + 1);
    inputStudent(&class[i]);
}
 printf("\n--- Displaying Student Details ---\n");
for (int i = 0; i < numStudents; i++) {
    displayStudent(&class[i]);
}
float avgGPA = calculateAverageGPA(class, numStudents);
    printf("\nAverage GPA of the class: %.2f\n", avgGPA);

     return 0;

}
