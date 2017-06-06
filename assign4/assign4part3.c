#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nqueens_library.h"

pthread_mutex_t printf_mutex = PTHREAD_MUTEX_INITIALIZER; //unused but allows make all to be used happily

int main (int argc, char *argv[]) {
   double elapsed;
   int first, flag, n, solutions;
   thread_info_t info;
   struct timespec start, finish;
   
   clock_gettime(CLOCK_REALTIME, &start);
   
   if (argc != 2) {
      printf("Improper arguments: %s n\n", argv[0]);
      exit(1);
   }
   
   n = atoi(argv[1]); //assumes correct user input
   info.n = n;
   
   if (n > 6)
      flag = 0;
   else
      flag = 1;
   info.out_flag = flag;
   
   solutions = 0;
   for (first = 0; first < n; first++) {
      info.first = first;
      queens_thread(&info);
     solutions += info.result;
   }
   
   clock_gettime(CLOCK_REALTIME, &finish);
   
   elapsed = (finish.tv_sec - start.tv_sec);
   elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
   
   printf("%d\nTime taken in seconds %f\n", solutions, elapsed);
   
   return 0;
}
