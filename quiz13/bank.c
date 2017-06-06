#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

double volatile BALANCE = 0.0;

void *deposit(void *args);
void *withdraw(void *args);

int main(int argc, char *argv[]) {
   if (argc != 5) {
      printf("Improper args. Call with %s a b c d\n", argv[0]);
      exit(1);
   }
   
   int dep[2] = {atoi(argv[1]), atoi(argv[2])};
   int wit[2] = {atoi(argv[3]), atoi(argv[4])};
   pthread_t depthread;
   pthread_t witthread;
   
   pthread_create(&depthread, NULL, deposit, dep);
   pthread_create(&witthread, NULL, withdraw, wit);
   
   pthread_join(depthread, NULL);
   pthread_join(witthread, NULL);
   
   printf("%f\n", BALANCE);
   
   exit(0);
}

void *deposit(void *args) {
   int i;
   int *ab = (int *)args;
   
   for (i = 0; i < ab[0]; i++)
      BALANCE += ab[1];
   
   pthread_exit(NULL);
}

void *withdraw(void *args) {
   int i;
   int *cd = (int *)args;
   
   for (i = 0; i < cd[0]; i++)
      BALANCE -= cd[1];
   
   pthread_exit(NULL);
}
