#include <stdio.h>

    int main() {
        int intarray[10] = {10,20,30,40,50,60,70,80,90,100};
        //-----------------------^
        int *pointer = &intarray[2];

        int *parray[10];

        int i;
        for (i = 0; i < 10; i++) {
            parray[i] = pointer + i;
        }

        for (i = 0; i < 10; i++) {
            if (parray[i] == &pointer[i+1]) {
                printf("sorry oun b dg khus hz\n");
            } else {
                printf("oun trov krob rg\n");
            }
        }

        return 0;
    }