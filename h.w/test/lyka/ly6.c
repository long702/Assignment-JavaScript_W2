#include <stdio.h>
  
typedef struct{
    int hours;
    int minutes;
    int second;
}Time;

Time sumtime(Time time1, Time time2){
    Time sum;

    sum.second = time1.second + time2.second;
    sum.minutes = time1.minutes + time2.minutes + sum.second / 60;
    sum.second %=60;

    sum.hours = time1.hours + time2.hours + sum.minutes / 60;
    sum.minutes %=60;

   return sum;
}

int comepareTime(Time time1, Time time2){
  if(time1.hours > time2.hours) return 1;
  if(time1.hours < time2.hours) return -1;

  if(time1.minutes > time2.minutes) return 1;
  if(time1.minutes < time2.minutes) return -1;

  if(time1.second > time2.second) return 1;
  if(time1.second < time2.second) return -1;

  return 0;
}
void printTime(const char* label, Time time){
    printf("%s %2d:%2d:%2d\n", label, time.hours, time.minutes, time.second);
}
int main(){

  Time time1 = {1, 45, 00};
  Time time2 = {1, 30, 00};
     printTime("Time1: ", time1);
     printTime("Time2: ", time2);
  Time Total = sumtime(time1, time2);
     printTime("sum  : ", Total);

int cmp = comepareTime(time1, time2);
   if(cmp == 1){
    printf("Result: Time1 is greater.\n");
   }else if(cmp == -1 ){
    printf("Result: Time2 is greater.\n");
   }else{
    printf("Result: Time both are equal.\n");
   }
   return 0;
}

