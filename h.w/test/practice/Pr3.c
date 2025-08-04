#include <stdio.h>
 
  int countVowels(const char* str){
    int count = 0;
    int i = 0;

    while(str[i] != '\0'){
      char ch = str[i];
      if (ch == 'A'  || ch == 'a' || ch == 'E' || ch == 'e' || ch == 'I' || ch == 'i' || ch == 'O' || ch == 'o' || ch == 'U'|| ch == 'u'){
          count++;
      }
          i++;
    }
    return count;
  }
int main(){
    const char* sentence = "who is the best?";
    int number = countVowels(sentence);

    printf("Number of vowels: %d\n", number);

    return 0;
}
