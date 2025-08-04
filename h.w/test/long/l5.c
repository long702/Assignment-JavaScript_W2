#include <stdio.h>
   int main(){
#define MAX_PATIENTS 100
#define MAX_ROOMS 10

typedef struct {
    char name[50];
    int age;
    char gender[10];
    int roomNumber;
    char admissionDate[20]; // format: dd/mm/yyyy
} Patient;

Patient patients[MAX_PATIENTS];
int totalPatients = 0;
int rooms[MAX_ROOMS]; // 0 = available, 1 = occupied   
void showMenu() {
    printf("=== Hospital Management Menu ===\n");
    printf("1. Admit New Patient\n");
    printf("2. View All Patients\n");
    printf("3. Search Patient\n");
    printf("4. Discharge Patient\n");
    printf("5. Show Room Availability\n");
    printf("0. Exit\n");
 }
   return 0;
}