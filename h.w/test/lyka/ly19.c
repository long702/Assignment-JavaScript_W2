#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define MAX_COURSES  50

struct Student {
    int id;
    char firstName[30];
    char lastName[30];
    int age;
    char gender[10];
    char address[100];
    char parentName[50];
    char major[50]; // Computer Science, etc.
    char course[50];
};

struct Course {
    char name[50];
    int enrolledIDs[MAX_STUDENTS];
    int enrollmentCount;
};

// Global storage
struct Student students[MAX_STUDENTS];
int studentCount = 0;

struct Course courses[MAX_COURSES];
int courseCount = 0;

// Function declarations
void addStudent();
void addCourse();
void enrollStudent();
void viewAllStudents();
void viewAllCourses();
void viewCourseEnrollment();
void saveToFile();

int findCourseIndex(const char *courseName);
int findStudentIndexByID(int id);
void selectMajor(char *major);

// Main menu
int main() {
    int choice;
    do {
        printf("\n====== Student Registration System ======\n");
        printf("1. Add Student\n");
        printf("2. Add Course\n");
        printf("3. Enroll Student in Course\n");
        printf("4. View All Students\n");
        printf("5. View All Courses\n");
        printf("6. View Course Enrollments\n");
        printf("7. Save to File\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch(choice) {
            case 1: addStudent(); break;
            case 2: addCourse(); break;
            case 3: enrollStudent(); break;
            case 4: viewAllStudents(); break;
            case 5: viewAllCourses(); break;
            case 6: viewCourseEnrollment(); break;
            case 7: saveToFile(); break;
            case 8: printf("Exiting program...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while(choice != 8);

    return 0;
}

void addStudent() {
    struct Student s;

    printf("Enter ID: ");
    scanf("%d", &s.id);
    getchar();
    printf("Enter First Name: ");
    fgets(s.firstName, sizeof(s.firstName), stdin);
    s.firstName[strcspn(s.firstName, "\n")] = 0;

    printf("Enter Last Name: ");
    fgets(s.lastName, sizeof(s.lastName), stdin);
    s.lastName[strcspn(s.lastName, "\n")] = 0;

    printf("Enter Age: ");
    scanf("%d", &s.age);
    getchar();
    printf("Enter Gender: ");
    fgets(s.gender, sizeof(s.gender), stdin);
    s.gender[strcspn(s.gender, "\n")] = 0;

    printf("Enter Current Address: ");
    fgets(s.address, sizeof(s.address), stdin);
    s.address[strcspn(s.address, "\n")] = 0;

    printf("Enter Parent's Name: ");
    fgets(s.parentName, sizeof(s.parentName), stdin);
    s.parentName[strcspn(s.parentName, "\n")] = 0;

    selectMajor(s.major);

    printf("Enter Course: ");
    fgets(s.course, sizeof(s.course), stdin);
    s.course[strcspn(s.course, "\n")] = 0;

    students[studentCount++] = s;

    printf("Student added successfully.\n");
}

void selectMajor(char *major) {
    int choice;
    printf("Select Major:\n");
    printf("1. Computer Science\n");
    printf("2. Cyber Security\n");
    printf("3. Telecommunication and Networking\n");
    printf("4. Digital Business\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    getchar();

    switch(choice) {
        case 1: strcpy(major, "Computer Science"); break;
        case 2: strcpy(major, "Cyber Security"); break;
        case 3: strcpy(major, "Telecommunication and Networking"); break;
        case 4: strcpy(major, "Digital Business"); break;
        default: strcpy(major, "Undeclared");
    }
}

void addCourse() {
    struct Course c;

    printf("Enter course name: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = 0;
    c.enrollmentCount = 0;

    courses[courseCount++] = c;

    printf("Course added successfully.\n");
}

void enrollStudent() {
    int studentID;
    char courseName[50];

    printf("Enter student ID to enroll: ");
    scanf("%d", &studentID);
    getchar();

    int sIndex = findStudentIndexByID(studentID);
    if (sIndex == -1) {
        printf("Student not found.\n");
        return;
    }

    printf("Enter course name to enroll to: ");
    fgets(courseName, sizeof(courseName), stdin);
    courseName[strcspn(courseName, "\n")] = 0;

    int cIndex = findCourseIndex(courseName);
    if (cIndex == -1) {
        printf("Course not found.\n");
        return;
    }

    courses[cIndex].enrolledIDs[courses[cIndex].enrollmentCount++] = studentID;

    printf("Student enrolled in course successfully.\n");
}

void viewAllStudents() {
    printf("\n--- Student List ---\n");
    for (int i = 0; i < studentCount; i++) {
        struct Student s = students[i];
        printf("ID: %d | Name: %s %s | Age: %d | Gender: %s | Address: %s | Parent: %s | Major: %s | Course: %s\n",
            s.id, s.firstName, s.lastName, s.age, s.gender, s.address, s.parentName, s.major, s.course);
    }
}

void viewAllCourses() {
    printf("\n--- Course List ---\n");
    for (int i = 0; i < courseCount; i++) {
        printf("%d. %s (%d students enrolled)\n", i + 1, courses[i].name, courses[i].enrollmentCount);
    }
}

void viewCourseEnrollment() {
    char courseName[50];
    printf("Enter course name to view enrollment: ");
    fgets(courseName, sizeof(courseName), stdin);
    courseName[strcspn(courseName, "\n")] = 0;

    int cIndex = findCourseIndex(courseName);
    if (cIndex == -1) {
        printf("Course not found.\n");
        return;
    }

    printf("Students enrolled in %s:\n", courses[cIndex].name);
    for (int i = 0; i < courses[cIndex].enrollmentCount; i++) {
        int sID = courses[cIndex].enrolledIDs[i];
        int sIndex = findStudentIndexByID(sID);
        if (sIndex != -1) {
            printf("- %s %s (ID: %d)\n", students[sIndex].firstName, students[sIndex].lastName, students[sIndex].id);
        }
    }
}

void saveToFile() {
    FILE *f = fopen("students.txt", "w");
    for (int i = 0; i < studentCount; i++) {
        struct Student s = students[i];
        fprintf(f, "%d,%s,%s,%d,%s,%s,%s,%s,%s\n",
            s.id, s.firstName, s.lastName, s.age, s.gender, s.address, s.parentName, s.major, s.course);
    }
    fclose(f);

    f = fopen("courses.txt", "w");
    for (int i = 0; i < courseCount; i++) {
        fprintf(f, "%s,%d\n", courses[i].name, courses[i].enrollmentCount);
    }
    fclose(f);

    printf("Data saved to files successfully.\n");
}

int findCourseIndex(const char *courseName) {
    for (int i = 0; i < courseCount; i++) {
        if (strcmp(courses[i].name, courseName) == 0)
            return i;
    }
    return -1;
}

int findStudentIndexByID(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id)
            return i;
    }
    return -1;
}
