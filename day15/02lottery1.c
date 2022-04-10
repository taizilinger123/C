#include <stdlib.h>
#include "02lottery1.h"
int lottery[7];
void create_lottery(void){
   int pos = 0;
   for(pos = 0;pos<=6;pos++){
      lottery[pos] = rand() % 36 + 1;
   }
}
