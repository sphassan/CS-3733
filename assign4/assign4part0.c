#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "nqueens_library.h"

pthread_mutex_t printf_mutex = PTHREAD_MUTEX_INITIALIZER; //unused but allows make all to be used happily

int main (int argc, char *argv[]) {
   int n;
   
   if (argc != 2) {
      printf("Improper arguments: %s n\n", argv[0]);
      exit(1);
   }
   
   n = atoi(argv[1]); //assumes correct user input
   
   generate_n_queens_serial(n, 0);
   
   return 0;
}
