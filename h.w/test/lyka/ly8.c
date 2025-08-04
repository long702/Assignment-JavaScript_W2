#include <stdio.h>
#include <string.h>

typedef struct {
    int hour;
    int minute;
    int second;
} Time;
typedef struct {
    char studentName[50];
    Time time;
} Attendance;

int compareTime(Time t1, Time t2) {
    if (t1.hour > t2.hour) return 1;
    if (t1.hour < t2.hour) return -1;

    if (t1.minute > t2.minute) return 1;
    if (t1.minute < t2.minute) return -1;

    if (t1.second > t2.second) return 1;
    if (t1.second < t2.second) return -1;

    return 0;
}

Attendance getLatest(Attendance attendances[5]) {
    Attendance latest = attendances[0];
    for (int i = 1; i < 5; i++) {
        if (compareTime(attendances[i].time, latest.time) > 0) {
            latest = attendances[i];
        }
    }
    return latest;
}

int main() {
    Attendance attendances[5] = {
        {"ly", {8, 15, 0}},
        {"thy", {8, 20, 30}},
        {"raksa", {8, 18, 45}},
        {"NamKea", {8, 25, 0}},
        {"lyka", {8, 22, 10}}
    };

    Attendance latestStudent = getLatest(attendances);

    printf("The latest student is: %s\n", latestStudent.studentName);

    return 0;
}
