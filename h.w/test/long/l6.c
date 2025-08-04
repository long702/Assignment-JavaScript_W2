#include <stdio.h>
#include <string.h>

#define MAX_PATIENTS 100
#define MAX_ROOMS 10

// Patient struct definition
typedef struct {
    char name[50];
    int age;
    char gender[10];
    int roomNumber;
    char admissionDate[20];
} Patient;

Patient patients[MAX_PATIENTS];
int totalPatients = 0;
int rooms[MAX_ROOMS] = {0}; // 0 = available, 1 = occupied

void admitPatient() {
    if (totalPatients >= MAX_PATIENTS) {
        printf("Hospital is full.\n");
        return;
    }

    int availableRoom = -1;
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i] == 0) {
            availableRoom = i + 1;
            break;
        }
    }

    if (availableRoom == -1) {
        printf("No available rooms.\n");
        return;
    }

    Patient newPatient;
    printf("Enter patient name: ");
    scanf(" %[^]", newPatient.name);
    printf("Enter age: ");
    scanf("%d", &newPatient.age);
    printf("Enter gender: ");
    scanf("%s", newPatient.gender);
    printf("Enter admission date (dd/mm/yyyy): ");
    scanf("%s", newPatient.admissionDate);
    newPatient.roomNumber = availableRoom;

    patients[totalPatients++] = newPatient;
    rooms[availableRoom - 1] = 1;

    printf("Patient admitted to room %d.\n", availableRoom);
}

void viewPatients() {
    if (totalPatients == 0) {
        printf("No patients admitted.\n");
        return;
    }

    printf("\n--- List of Patients ---\n");
    for (int i = 0; i < totalPatients; i++) {
        printf("%d. Name: %s, Age: %d, Gender: %s, Room: %d, Date: %s\n",
               i + 1, patients[i].name, patients[i].age, patients[i].gender,
               patients[i].roomNumber, patients[i].admissionDate);
    }
}

void searchPatient() {
    char searchName[50];
    printf("Enter patient name to search: ");
    scanf(" %[^]", searchName);

    int found = 0;
    for (int i = 0; i < totalPatients; i++) {
        if (strcmp(patients[i].name, searchName) == 0) {
            printf("Found: Name: %s, Age: %d, Gender: %s, Room: %d, Date: %s\n",
                   patients[i].name, patients[i].age, patients[i].gender,
                   patients[i].roomNumber, patients[i].admissionDate);
            found = 1;
            break;
        }
    }
    if (!found) printf("Patient not found.\n");
}

void dischargePatient() {
    char name[50];
    printf("Enter patient name to discharge: ");
    scanf(" %[^]", name);

    for (int i = 0; i < totalPatients; i++) {
        if (strcmp(patients[i].name, name) == 0) {
            rooms[patients[i].roomNumber - 1] = 0;
            for (int j = i; j < totalPatients - 1; j++) {
                patients[j] = patients[j + 1];
            }
            totalPatients--;
            printf("Patient discharged.\n");
            return;
        }
    }
    printf("Patient not found.\n");
}

void showRoomStatus() {
    printf("\n--- Room Status ---\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("Room %d: %s\n", i + 1, rooms[i] ? "Occupied" : "Available");
    }
}

void showMenu() {
    printf("\n===== Hospital Management System =====\n");
    printf("1. Admit New Patient\n");
    printf("2. View All Patients\n");
    printf("3. Search Patient\n");
    printf("4. Discharge Patient\n");
    printf("5. Show Room Availability\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    do {
        showMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: admitPatient(); break;
            case 2: viewPatients(); break;
            case 3: searchPatient(); break;
            case 4: dischargePatient(); break;
            case 5: showRoomStatus(); break;
            case 0: printf("Exiting program.\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
