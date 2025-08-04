#include <stdio.h>

// Define Time structure
typedef struct {
    int hours;
    int minutes;
    int seconds;
} Time;

// Function to return the sum of two times
Time sumTime(Time time1, Time time2) {
    Time result;

    result.seconds = time1.seconds + time2.seconds;
    result.minutes = time1.minutes + time2.minutes + result.seconds / 60;
    result.seconds %= 60;

    result.hours = time1.hours + time2.hours + result.minutes / 60;
    result.minutes %= 60;

    return result;
}

// Function to compare two times
// Returns: 1 if time1 > time2, -1 if time2 > time1, 0 if equal
int compareTime(Time time1, Time time2) {
    if (time1.hours > time2.hours) return 1;
    if (time1.hours < time2.hours) return -1;

    if (time1.minutes > time2.minutes) return 1;
    if (time1.minutes < time2.minutes) return -1;

    if (time1.seconds > time2.seconds) return 1;
    if (time1.seconds < time2.seconds) return -1;

    return 0;
}

// Function to print a time in hh:mm:ss format
void printTime(const char* label, Time t) {
    printf("%s %02d:%02d:%02d\n", label, t.hours, t.minutes, t.seconds);
}

int main() {
    // Create two Time variables
    Time time1 = {1, 45, 0};
    Time time2 = {1, 30, 0};

    // Print the two times
    printTime("Time 1:", time1);
    printTime("Time 2:", time2);

    // Calculate and print the sum
    Time total = sumTime(time1, time2);
    printTime("Sum:", total);

    // Compare and print the result
    int cmp = compareTime(time1, time2);
    if (cmp == 1)
        printf("Result: Time 1 is greater.\n");
    else if (cmp == -1)
        printf("Result: Time 2 is greater.\n");
    else
        printf("Result: Both times are equal.\n");

    return 0;
}
