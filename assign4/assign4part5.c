#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nqueens_library.h"

pthread_mutex_t printf_mutex = PTHREAD_MUTEX_INITIALIZER;

int main (int argc, char *argv[]) {
   double elapsed;
   int first, flag, n, solutions;
   pthread_t *threads;
   thread_info_t *info;
   struct timespec start, finish;
   
   clock_gettime(CLOCK_REALTIME, &start);
   
   if (argc != 2) {
      printf("Improper arguments: %s n\n", argv[0]);
      exit(1);
   }
   
   n = atoi(argv[1]); //assumes correct user input
   info = malloc(sizeof(thread_info_t) * n);
   threads = malloc(sizeof(pthread_t) * n);
      
   if (n > 6)
      flag = 0;
   else
      flag = 1;
   
   for (first = 0; first < n; first++) {
      info[first].n = n;
      info[first].out_flag = flag;
      info[first].first = first;
      pthread_create(&threads[first], NULL, queens_thread_safe, &info[first]);
   }
   
   for (first = 0; first < n; first++)
      pthread_join(threads[first], NULL);
   
   solutions = 0;
   for (first = 0; first < n; first++)
      solutions += info[first].result;
   
   clock_gettime(CLOCK_REALTIME, &finish);
   
   elapsed = (finish.tv_sec - start.tv_sec);
   elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
   
   printf("%d\nTime taken in seconds: %f\n", solutions, elapsed);

   return 0;
}
