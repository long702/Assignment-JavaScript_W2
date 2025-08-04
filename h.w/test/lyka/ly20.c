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
    char fatherName[50];
    char motherName[50];
    char major[50]; // Predefined major
    char course[50]; // Enrolled course
    float courseCost; // in $/year
};

struct Course {
    char name[50];
    float cost;
    int enrolledIDs[100];
    int enrollmentCount;
};

// Global arrays
struct Student students[MAX_STUDENTS];
int studentCount = 0;

struct Course courses[MAX_COURSES];
int courseCount = 0;

// Function declarations
void addStudent();
void addCourse();
void enrollStudent();
void viewAllStudents();
void viewAllDocuments();
void viewCourseRegistration();
void saveToFile();
int findCourseIndex(const char *courseName);
int findStudentIndexByID(int id);
void selectMajor(char *major);

int main() {
    int choice;
    do {
        printf("\n===== Student Registration System =====\n");
        printf("1. Add Student\n");
        printf("2. Add Course\n");
        printf("3. Enroll Student in Course\n");
        printf("4. View All Students\n");
        printf("5. View All Documents\n");
        printf("6. View Course Registration\n");
        printf("7. Save to File\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1: addStudent(); break;
            case 2: addCourse(); break;
            case 3: enrollStudent(); break;
            case 4: viewAllStudents(); break;
            case 5: viewAllDocuments(); break;
            case 6: viewCourseRegistration(); break;
            case 7: saveToFile(); break;
            case 8: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 8);

    return 0;
}

// ========== FUNCTION IMPLEMENTATIONS ==========

void addStudent() {
    struct Student s;

    printf("Enter Student ID: ");
    scanf("%d", &s.id); getchar();

    printf("Enter First Name: ");
    fgets(s.firstName, sizeof(s.firstName), stdin);
    s.firstName[strcspn(s.firstName, "\n")] = 0;

    printf("Enter Last Name: ");
    fgets(s.lastName, sizeof(s.lastName), stdin);
    s.lastName[strcspn(s.lastName, "\n")] = 0;

    printf("Enter Age: ");
    scanf("%d", &s.age); getchar();

    printf("Enter Gender: ");
    fgets(s.gender, sizeof(s.gender), stdin);
    s.gender[strcspn(s.gender, "\n")] = 0;

    printf("Enter Address: ");
    fgets(s.address, sizeof(s.address), stdin);
    s.address[strcspn(s.address, "\n")] = 0;

    printf("Enter Father's Name: ");
    fgets(s.fatherName, sizeof(s.fatherName), stdin);
    s.fatherName[strcspn(s.fatherName, "\n")] = 0;

    printf("Enter Mother's Name: ");
    fgets(s.motherName, sizeof(s.motherName), stdin);
    s.motherName[strcspn(s.motherName, "\n")] = 0;

    selectMajor(s.major);

    printf("Enter Course Name: ");
    fgets(s.course, sizeof(s.course), stdin);
    s.course[strcspn(s.course, "\n")] = 0;

    printf("Enter Course Cost ($/year): ");
    scanf("%f", &s.courseCost); getchar();

    students[studentCount++] = s;
    printf("Student added successfully.\n");
}

void selectMajor(char *major) {
    int choice;
    printf("Select Major:\n");
    printf("1. Computer Science\n");
    printf("2. Cyber Security\n");
    printf("3. Telecommunications\n");
    printf("4. Digital Business Networking\n");
    printf("Enter choice: ");
    scanf("%d", &choice); getchar();

    switch (choice) {
        case 1: strcpy(major, "Computer Science"); break;
        case 2: strcpy(major, "Cyber Security"); break;
        case 3: strcpy(major, "Telecommunications"); break;
        case 4: strcpy(major, "Digital Business Networking"); break;
        default: strcpy(major, "Undeclared");
    }
}

void addCourse() {
    struct Course c;
    printf("Enter Course Name: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = 0;

    printf("Enter Course Cost ($/year): ");
    scanf("%f", &c.cost); getchar();

    c.enrollmentCount = 0;
    courses[courseCount++] = c;
    printf("Course added successfully.\n");
}

void enrollStudent() {
    int studentID;
    char courseName[50];

    printf("Enter Student ID to Enroll: ");
    scanf("%d", &studentID); getchar();

    int sIndex = findStudentIndexByID(studentID);
    if (sIndex == -1) {
        printf("Student not found.\n");
        return;
    }

    printf("Enter Course Name to Enroll In: ");
    fgets(courseName, sizeof(courseName), stdin);
    courseName[strcspn(courseName, "\n")] = 0;

    int cIndex = findCourseIndex(courseName);
    if (cIndex == -1) {
        printf("Course not found.\n");
        return;
    }

    courses[cIndex].enrolledIDs[courses[cIndex].enrollmentCount++] = studentID;
    printf("Student enrolled successfully.\n");
}

void viewAllStudents() {
    printf("\n--- Student List ---\n");
    for (int i = 0; i < studentCount; i++) {
        struct Student s = students[i];
        printf("ID: %d | Name: %s %s | Age: %d | Gender: %s | Address: %s | Major: %s | Course: %s\n",
            s.id, s.firstName, s.lastName, s.age, s.gender, s.address, s.major, s.course);
    }
}

void viewAllDocuments() {
    printf("\n--- All Student Documents ---\n");
    for (int i = 0; i < studentCount; i++) {
        struct Student s = students[i];
        printf("\n[Student ID: %d]\n", s.id);
        printf("Name       : %s %s\n", s.firstName, s.lastName);
        printf("Age/Gender : %d / %s\n", s.age, s.gender);
        printf("Address    : %s\n", s.address);
        printf("Father     : %s\n", s.fatherName);
        printf("Mother     : %s\n", s.motherName);
        printf("Major      : %s\n", s.major);
        printf("Course     : %s\n", s.course);
        printf("Course Cost: $%.2f/year\n", s.courseCost);
    }
}

void viewCourseRegistration() {
    char courseName[50];
    printf("Enter Course Name: ");
    fgets(courseName, sizeof(courseName), stdin);
    courseName[strcspn(courseName, "\n")] = 0;

    int cIndex = findCourseIndex(courseName);
    if (cIndex == -1) {
        printf("Course not found.\n");
        return;
    }

    printf("Students enrolled in %s:\n", courses[cIndex].name);
    for (int i = 0; i < courses[cIndex].enrollmentCount; i++) {
        int sid = courses[cIndex].enrolledIDs[i];
        int sIndex = findStudentIndexByID(sid);
        if (sIndex != -1) {
            struct Student s = students[sIndex];
            printf("- %s %s (ID: %d)\n", s.firstName, s.lastName, s.id);
        }
    }
}

void saveToFile() {
    FILE *sf = fopen("students.txt", "w");
    for (int i = 0; i < studentCount; i++) {
        struct Student s = students[i];
        fprintf(sf, "%d,%s,%s,%d,%s,%s,%s,%s,%s,%s,%.2f\n",
            s.id, s.firstName, s.lastName, s.age, s.gender, s.address,
            s.fatherName, s.motherName, s.major, s.course, s.courseCost);
    }
    fclose(sf);

    FILE *cf = fopen("courses.txt", "w");
    for (int i = 0; i < courseCount; i++) {
        fprintf(cf, "%s,%.2f,%d\n", courses[i].name, courses[i].cost, courses[i].enrollmentCount);
    }
    fclose(cf);

    printf("Data saved to students.txt and courses.txt successfully.\n");
}

// ========== UTILITY FUNCTIONS ==========

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
