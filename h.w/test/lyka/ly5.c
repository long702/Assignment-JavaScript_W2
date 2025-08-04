#include <stdio.h>

typedef struct {
    char name[50];
    int id;
    float scores[5];
} Student;

double getScoresAverage(Student student) {
    float sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += student.scores[i];
    }
    return sum / 5;
}

int main() {

    Student viseth = {"Viseth",99, {84.5, 78, 91.5, 85, 70}};
    Student sousdey = {"Sousdey", 100, {71, 65.8, 81.5, 77, 60.8}};

    double avgViseth = getScoresAverage(viseth);
    double avgSousdey = getScoresAverage(sousdey);

    printf("Student Name1: %s\n", viseth.name);
    printf("Student ID: %d\n", viseth.id);
    printf("Scores: ");

    for (int i = 0; i < 5; i++) {
        printf("%.1f ", viseth.scores[i]);
    }   printf("\nAverage Score: %.2f\n\n", avgViseth);

    printf("Student Name2: %s\n", sousdey.name);
    printf("Student ID: %d\n", sousdey.id);
    printf("Scores: ");

    for (int i = 0; i < 5; i++) {
        printf("%.1f ", sousdey.scores[i]);
    }   printf("\nAverage Score: %.2f\n", avgSousdey);

    return 0;
}

   