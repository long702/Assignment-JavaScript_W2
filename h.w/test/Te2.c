#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// return a random number betwee min and max
int getRandomInRange(int min, int max) {
    return min + rand() % (max - min + 1);        
}

int attack(){
     return getRandomInRange(5,12);
     
}

int heal(){
     return getRandomInRange(8,15);
          
}

int specialAttack(){
     return getRandomInRange(8,25);
}

int monsterAttack(){
     return getRandomInRange(8,12);
     
}

void printStatus(int knightLife, int monsterLife){
    printf("\n");
    printf("Knight's HP : %d\n", knightLife );
    printf("Monster's HP : %d\n", monsterLife);
    printf("\n");
}
void printRoundLog(int damage2Kni, int damage2Mon, int healed, char choice){
     printf("\n");
     if (choice == 'A'){
          printf("You attacked the monster and dealt %d damage.\n", damage2Mon);
     }
     else if (choice == 'H'){
          printf("You healed yourself for %d points.\n", healed);

          
     }
     else if (choice == 'S'){
          printf("You used SPECIAL ATTACK and dealt %d damage.\n",damage2Mon);
     } 
     printf("The monster attacked and dealt %d damage.\n", damage2Kni);
}

int main() {
    srand(time(NULL));                 // Seed random number generator

    int knightLife = 40;            // The knight lives
    int monsterLife = 40;          // The monster lives
    int turn = 1;                 // The round index 

    while (knightLife > 0 && monsterLife > 0) { 
     char choice;
     int damage2Mon =0;
     int damage2Kni=0;
     int healed=0;  
     printf("--------Round %d--------\n", turn);
     printf("Choose your action : (A)ttack, (H)eal, (S)pecial Attack\n>");
     scanf(" %c", &choice);
          if (choice == 'A'){
          damage2Mon = attack();
          damage2Kni= monsterAttack();
          monsterLife -= damage2Mon;
          knightLife -= damage2Kni;
          }
          else if (choice == 'H'){
          healed = heal();
          knightLife += healed;
          damage2Kni = monsterAttack();
          knightLife -= damage2Kni;
          }
          else if (choice == 'S'){
               if (turn % 3 == 0){
                    damage2Mon = specialAttack();
                    damage2Kni = monsterAttack();
                    monsterLife -= damage2Mon;
                    knightLife -= damage2Kni;

               }
               else{
                    printf("\n");
                    printf("Special Attack is only available after every 3 turns\n");
                    printf("\n");
                    continue;
               }

          }

          else{
               printf("Invalid.\n");
               continue;
          }
     printRoundLog(damage2Kni, damage2Mon, healed, choice);
     printStatus(knightLife,monsterLife);
     turn++;
    }
    if (knightLife <= 0 && monsterLife <= 0) {
        printf("\nIt's a draw!\n");
    } else if (knightLife <= 0) {
        printf("\nThe knight has fallen. Monster wins!\n");
    } else {
        printf("\nMonster is defeated. Knight wins!\n");
    }

    return 0;
}