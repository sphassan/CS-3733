#include <stdio.h>
#include <time.h>

void function_to_time(void);

int main(void) {
   time_t tend, tstart;
   char bend[99], bstart[99];

   tstart = time(NULL);
   function_to_time();
   tend = time(NULL);
   ctime_r(&tstart, bstart);
   ctime_r(&tend, bend);
   printf("The time before was %sThe time after  was %s", bstart, bend);
   return 0;
}
