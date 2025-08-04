#include <stdio.h>
   int main(){
int RNG(int main, int max){ //Random Number Genertor
    return min + rand() % (max-min+1);
}
int attack(){               //Knight's Attack
    int atk = RNG(5,12);
    return atk;
}
int heal(){                 //Knight's healling
    int Heal = RNG(8,15);
    return heal;
}
int spcatk(int roundpick){  //Knight's special Attack
    if (roundpick % 3 == 0){
        int spcatk = RNG(8,25);
        return spcatk;
    }else {
        return 0;
    }
}
int monsteratk(){            //Monster's counterAttack
    int matk = RNG(8,12);
    return matk;
}
void printstatus(int Hp, int MHp){    //Print current lives of Knight and Monster
    (Hp < 0) ? printf("\nKnight Hp : 0") : printf("\nKnight Hp : %d",Hp);
    (MHp < 0) ? printf("\nMonster Hp : 0") : printf("\nMonster Hp : %d",MHp);
     printf("\n-----------------------------------------");
}
void printroundlog(char option, int choice, int monsterDMG){  //Describes what happened during thee round
    if (option == 'A'){
        printf("You Attacked the monster and dealth %d damage!\n",choice);
    }else if (option == 'H'){
        printf("You healed yourself %d health!\n", choice);
    }else {
        printf("You used special attack ! and Dealt %d damage!\n", choice);
    }
    printf("The MonsterAttacked and dealt %d damage !\n", MonsterDMG);
}













