#include <stdio.h>
   
      typedef struct{
        char * brand;
        int model;
   }vehicle;
   int main() {

   vehicle mycar;
   mycar.brand = "ford raptor";
   mycar.model = 2025;
   printf("%s is %d modern new product has limit.", mycar.brand, mycar.model);

    return 0;
   }