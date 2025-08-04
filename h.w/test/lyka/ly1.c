#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_COURSES 50
#define MAX_NAME_LEN 50
#define MAX_COURSE_PER_STUDENT 10

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int registeredCourseIds[MAX_COURSE_PER_STUDENT];
    int courseCount;
} Student;

typedef struct {
    int id;
    char title[MAX_NAME_LEN];
    int enrolledStudentIds[MAX_STUDENTS];
    int studentCount;
} Course;

Student students[MAX_STUDENTS];
Course courses[MAX_COURSES];
int studentCount = 0;
int courseCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Student list is full.\n");
        return;
    }
    Student s;
    s.id = studentCount + 1;
    printf("Enter student name: ");
    scanf("%49s", s.name); // safer scanf
    s.courseCount = 0;
    students[studentCount++] = s;
    printf("Student added successfully with ID %d.\n", s.id);
}

void addCourse() {
    if (courseCount >= MAX_COURSES) {
        printf("Course list is full.\n");
        return;
    }
    Course c;
    c.id = courseCount + 1;
    printf("Enter course title: ");
    scanf("%49s", c.title); // safer scanf
    c.studentCount = 0;
    courses[courseCount++] = c;
    printf("Course added successfully with ID %d.\n", c.id);
}

void registerStudentToCourse() {
    int sid, cid;
    printf("Enter student ID: ");
    scanf("%d", &sid);
    printf("Enter course ID: ");
    scanf("%d", &cid);

    if (sid < 1 || sid > studentCount || cid < 1 || cid > courseCount) {
        printf("Invalid student or course ID.\n");
        return;
    }

    Student *s = &students[sid - 1];
    Course *c = &courses[cid - 1];

    if (s->courseCount >= MAX_COURSE_PER_STUDENT) {
        printf("Student already registered in maximum number of courses.\n");
        return;
    }

    for (int i = 0; i < s->courseCount; i++) {
        if (s->registeredCourseIds[i] == cid) {
            printf("Student already registered in this course.\n");
            return;
        }
    }

    s->registeredCourseIds[s->courseCount++] = cid;
    c->enrolledStudentIds[c->studentCount++] = sid;
    printf("Student ID %d registered to course ID %d.\n", sid, cid);
}

void viewAllStudents() {
    printf("\nList of Students:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Name: %s, Courses: ", students[i].id, students[i].name);
        for (int j = 0; j < students[i].courseCount; j++) {
            printf("%d ", students[i].registeredCourseIds[j]);
        }
        printf("\n");
    }
}

void viewAllCourses() {
    printf("\nList of Courses:\n");
    for (int i = 0; i < courseCount; i++) {
        printf("ID: %d, Title: %s\n", courses[i].id, courses[i].title);
    }
}

void viewCourseEnrollment() {
    int cid;
    printf("Enter course ID to view enrollment: ");
    scanf("%d", &cid);

    if (cid < 1 || cid > courseCount) {
        printf("Invalid course ID.\n");
        return;
    }

    Course *c = &courses[cid - 1];
    printf("Students enrolled in course '%s':\n", c->title);
    for (int i = 0; i < c->studentCount; i++) {
        int sid = c->enrolledStudentIds[i];
        printf("ID: %d, Name: %s\n", students[sid - 1].id, students[sid - 1].name);
    }
}

void saveToFile() {
    FILE *f = fopen("data.txt", "w");
    if (!f) {
        printf("Failed to open file for saving.\n");
        return;
    }

    fprintf(f, "%d %d\n", studentCount, courseCount);

    for (int i = 0; i < studentCount; i++) {
        fprintf(f, "%d %s %d ", students[i].id, students[i].name, students[i].courseCount);
        for (int j = 0; j < students[i].courseCount; j++) {
            fprintf(f, "%d ", students[i].registeredCourseIds[j]);
        }
        fprintf(f, "\n");
    }

    for (int i = 0; i < courseCount; i++) {
        fprintf(f, "%d %s %d ", courses[i].id, courses[i].title, courses[i].studentCount);
        for (int j = 0; j < courses[i].studentCount; j++) {
            fprintf(f, "%d ", courses[i].enrolledStudentIds[j]);
        }
        fprintf(f, "\n");
    }

    fclose(f);
    printf("Data saved successfully.\n");
}

void loadFromFile() {
    FILE *f = fopen("data.txt", "r");
    if (!f) {
        printf("No saved file found.\n");
        return;
    }

    fscanf(f, "%d %d\n", &studentCount, &courseCount);

    for (int i = 0; i < studentCount; i++) {
        fscanf(f, "%d %s %d", &students[i].id, students[i].name, &students[i].courseCount);
        for (int j = 0; j < students[i].courseCount; j++) {
            fscanf(f, "%d", &students[i].registeredCourseIds[j]);
        }
    }

    for (int i = 0; i < courseCount; i++) {
        fscanf(f, "%d %s %d", &courses[i].id, courses[i].title, &courses[i].studentCount);
        for (int j = 0; j < courses[i].studentCount; j++) {
            fscanf(f, "%d", &courses[i].enrolledStudentIds[j]);
        }
    }

    fclose(f);
    printf("Data loaded successfully.\n");
}

int main() {
    int choice;
    loadFromFile();

    while (1) {
        printf("\n====== Student Course Registration System ======\n");
        printf("1. Add Student\n");
        printf("2. Add Course\n");
        printf("3. Register Student to Course\n");
        printf("4. View All Students\n");
        printf("5. View All Courses\n");
        printf("6. View Course Enrollment\n");
        printf("7. Save to File\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: addCourse(); break;
            case 3: registerStudentToCourse(); break;
            case 4: viewAllStudents(); break;
            case 5: viewAllCourses(); break;
            case 6: viewCourseEnrollment(); break;
            case 7: saveToFile(); break;
            case 8: saveToFile(); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}