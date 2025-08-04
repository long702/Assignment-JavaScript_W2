#include <stdio.h>

typedef struct{
    int hours;
    int minutes;
    int seconds;
} Time;

Time sumTime(Time t1, Time t2){
     Time sum;

    sum.seconds = time1.seconds + time2.seconds;
    sum.minutes = time1.minutes + time2.minutes + sum.seconds /60;
       sum.seconds %= 60;

    sum.hours = time1.hours + time2.hours + sum.minutes /60;
       sum.minutes %= 60;

       return sum;
}

int main(){
    
}