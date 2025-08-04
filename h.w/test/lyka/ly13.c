#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100
#define MAX_ROOMS 20

typedef struct {
    char name[50];
    int age;
    int roomNumber;
    char admissionDate[20];
    int active; // 1 = active, 0 = removed
} Patient;

Patient patients[MAX_PATIENTS];
int patientCount = 0;
int rooms[MAX_ROOMS] = {0}; // 0 = available, 1 = occupied

// Function prototypes
void menu();
void addPatient();
void viewPatients();
void updatePatient();
void dischargePatient();
void searchPatient();
void viewSummary();
int findAvailableRoom();
void pause();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;

    do {
        system("cls");
        printf("===== HOSPITAL MANAGEMENT SYSTEM =====\n");
        printf("1. Add New Patient\n");
        printf("2. View All Patients\n");
        printf("3. Update Patient Info\n");
        printf("4. Discharge Patient\n");
        printf("5. Search Patient\n");
        printf("6. View Summary\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: updatePatient(); break;
            case 4: dischargePatient(); break;
            case 5: searchPatient(); break;
            case 6: viewSummary(); break;
            case 7: printf("Exiting... Goodbye see you later!\n"); break;
            default: printf("Invalid choice!\n"); pause();
        }
    } while (choice != 7);
}

void addPatient() {
    if (patientCount >= MAX_PATIENTS) {
        printf("Hospital is full!\n");
        pause();
        return;
    }

    int room = findAvailableRoom();
    if (room == -1) {
        printf("No available rooms!\n");
        pause();
        return;
    }

    Patient p;
    printf("Enter patient name: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = '\0'; // remove newline

    printf("Enter age: ");
    scanf("%d", &p.age);
    getchar();

    printf("Enter admission date (YYYY-MM-DD): ");
    fgets(p.admissionDate, sizeof(p.admissionDate), stdin);
    p.admissionDate[strcspn(p.admissionDate, "\n")] = '\0';

    p.roomNumber = room + 101;
    p.active = 1;

    patients[patientCount++] = p;
    rooms[room] = 1;

    printf("Patient admitted to room %d.\n", p.roomNumber);
    pause();
}

void viewPatients() {
    printf("\n=== List of Patients ===\n");
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].active) {
            printf("%d. %s | Age: %d | Room: %d | Date: %s\n",
                   i + 1, patients[i].name, patients[i].age,
                   patients[i].roomNumber, patients[i].admissionDate);
        }
    }
    pause();
}

void updatePatient() {
    char name[50];
    printf("Enter name of patient to update: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].active && strcmp(patients[i].name, name) == 0) {
            printf("Found patient. Enter new age: ");
            scanf("%d", &patients[i].age);
            getchar();

            printf("Enter new admission date: ");
            fgets(patients[i].admissionDate, sizeof(patients[i].admissionDate), stdin);
            patients[i].admissionDate[strcspn(patients[i].admissionDate, "\n")] = '\0';

            printf("Patient updated successfully.\n");
            pause();
            return;
        }
    }

    printf("Patient not found.\n");
    pause();
}

void dischargePatient() {
    char name[50];
    printf("Enter name of patient to discharge: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].active && strcmp(patients[i].name, name) == 0) {
            patients[i].active = 0;
            int roomIndex = patients[i].roomNumber - 101;
            rooms[roomIndex] = 0;
            printf("Patient discharged. Room %d is now available.\n", patients[i].roomNumber);
            pause();
            return;
        }
    }

    printf("Patient not found.\n");
    pause();
}

void searchPatient() {
    char name[50];
    printf("Enter name to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].active && strstr(patients[i].name, name)) {
            printf("%s | Age: %d | Room: %d | Date: %s\n",
                   patients[i].name, patients[i].age,
                   patients[i].roomNumber, patients[i].admissionDate);
            found = 1;
        }
    }

    if (!found) printf("No matching patients found.\n");
    pause();
}

void viewSummary() {
    int occupied = 0;
    for (int i = 0; i < MAX_ROOMS; i++)
        if (rooms[i]) occupied++;

    printf("\n=== Hospital Summary ===\n");
    printf("Total patients: %d\n", patientCount);
    printf("Active patients: %d\n", occupied);
    printf("Available rooms: %d\n", MAX_ROOMS - occupied);
    pause();
}

int findAvailableRoom() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i] == 0) return i;
    }
    return -1;
}

void pause() {
    printf("\nPress Enter to continue...");
    getchar();
}
