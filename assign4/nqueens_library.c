#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nqueens_library.h"

int check_diagonal(int *list, int n) {
   int col, deltc, deltr, row, x, y;
   
   for (x = 0; x < n; x++) {
      col = x;
      row = list[x];
      
      for (y = 0; y < n; y++) {
         if (x == y)
            continue;
         
         deltc = col - y;
         deltr = row - list[y];
         
         if (deltr == deltc || deltr == (-1) * deltc)
            return 0;
      }
   }
   
   return 1;
}

int generate_n_queens_serial(int n, int print_flag) {
   char *output;
   int *list, solutions, x;
   
   output = malloc((n * 4) + 2);
   list = malloc(sizeof(int) * n);
   
   for (x = 0; x < n; x++)
      list[x] = x;
   
   solutions = 0;
   do {
      if (check_diagonal(list, n)) {
         solutions++;
         
         if (print_flag) {
            get_array_string(list, n, output);
            printf("%s", output);
            output = calloc(sizeof(char), (n * 4) + 2);
         }
      }
   } while (!next_permutation(list, n));
   
   return solutions;
}

int generate_n_queens_serial_one(int n, int out_flag, int first) {
   char *output;
   int *list, solutions, x;
   
   output = malloc((n * 4) + 2);
   list = malloc(sizeof(int) * n);
   list[0] = first;
   
   for (x = 1; x < n; x++) {
      if (x <= first)
         list[x] = x-1;
      else
         list[x] = x;
   }
   
   solutions = 0;
   do {
      if (list[0] != first)
         break;
      
      if (check_diagonal(list, n)) {
         solutions++;
         
         if (out_flag) {
            get_array_string(list, n, output);
            printf("%s", output);
            output = calloc(sizeof(char), (n * 4) + 2);
         }
      }
   } while (!next_permutation(list, n));
   
   return solutions;
}

int generate_n_queens_serial_one_safe(int n, int out_flag, int first) {
   char *output;
   int *list, solutions, x;
   
   output = malloc((n * 4) + 2);
   list = malloc(sizeof(int) * n);
   list[0] = first;
   
   for (x = 1; x < n; x++) {
      if (x <= first)
         list[x] = x-1;
      else
         list[x] = x;
   }
   
   solutions = 0;
   do {
      if (list[0] != first)
         break;
      
      if (check_diagonal(list, n)) {
         solutions++;
         
         if (out_flag) {
            get_array_string(list, n, output);
            pthread_mutex_lock(&printf_mutex);
            printf("%s", output);
            pthread_mutex_unlock(&printf_mutex);
            output = calloc(sizeof(char), (n * 4) + 2);
         }
      }
   } while (!next_permutation(list, n));
   
   return solutions;
}

void get_array_string(int *list, int n, char *s) {
   int x;
   
   for (x = 0; x < n; x++)
      sprintf(s + strlen(s), "%4d", list[x]);
   
   sprintf(s + strlen(s), "\n");
}

int next_permutation(int *list, int n) {
   int i, k, temp, x, y;
   
   if (n == 1)
      return 1;
   
   i = -1;
   k = -1;
   for (x = n - 2; x >= 0; x--) {
      if (list[x] < list[x+1]) {
         k = x;
         break;
      }
   }
   
   if (k == -1)
      return 1;
   
   for (x = n - 1; x >= k + 1; x--) {
      if (list[k] < list[x]) {
         i = x;
         break;
      }
   }
   
   temp = list[k];
   list[k] = list[i];
   list[i] = temp;
   
   x = k + 1;
   y = n - 1;
   
   while (y > x) {
      temp = list[y];
      list[y] = list[x];
      list[x] = temp;
      x++;
      y--;
   }
   
   return 0;
}


void *queens_thread(void *infopointer) {
   thread_info_t *info = (thread_info_t*)infopointer;
   
   info -> result = generate_n_queens_serial_one(info -> n, info -> out_flag, info -> first);
   
   printf("First: %d Solutions: %d\n", info -> first, info -> result);
   
   return NULL;
}

void *queens_thread_safe(void *infopointer) {
   thread_info_t *info = (thread_info_t*)infopointer;
   
   info -> result = generate_n_queens_serial_one_safe(info -> n, info -> out_flag, info -> first);
   
   pthread_mutex_lock(&printf_mutex);
   printf("First: %d Solutions: %d\n", info -> first, info -> result);
   pthread_mutex_unlock(&printf_mutex);
   
   return NULL;
}
