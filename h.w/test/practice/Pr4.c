#include <stdio.h>

// Driver code
int main()
{
    int i = 0;

    // for loop with continue
    for (i = 1; i <= 10; i++) {
        if (i == 5 || i == 7) {
            continue;
        }
        printf("%d ", i);
    }
    printf("\n");

    // while loop with break
    i = 1;
    while (i <= 10) {
        if (i == 7) {
            break;
        }
        printf("%d ", i++);
    }
    printf("\n");

    // do_while loop
    i = 1;
    do {
        printf("%d ", i++);
    } while (i <= 10);
    printf("\n");

    // goto statement
    i = 1;
any_label:
    printf("%d ", i++);
    if (i <= 10) {
        goto any_label;
    }

    return 0;
}