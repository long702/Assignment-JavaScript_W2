#include <stdio.h>
#include <string.h>
int main() {
  char first_name ="john";
  char last_name[] = "long";
  char name[100];

  last_name[0] = 'L';
  sprintf(name, "%s %s", first_name, last_name);
  if (strncmp(name, "John long", 100) == 0) {
      printf("Done!\n");
  }
  name[0]='\0';
  strncat(name,first_name,7);
  strncat(name,last_name,25);
  printf("%s\n",name);
  return 0;
}
