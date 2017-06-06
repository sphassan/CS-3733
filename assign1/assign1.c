#include <stdio.h>
#include <stdlib.h>
#include "pslibrary.h"

int main(int argc, char *argv[]) {
   int a1, a2, a3, a4, a5, a6, a7;
   char *heading;
   int mxsz;
   char *s1, *s2;
   
   if (argc != 8) {
      printf("Incorrect invocation. Usage: %s int 1 int 2 ... int 3\n", argv[0]);
      exit(1);
   }
   
   a1 = atoi(argv[1]);
   a2 = atoi(argv[2]);
   a3 = atoi(argv[3]);
   a4 = atoi(argv[4]);
   a5 = atoi(argv[5]);
   a6 = atoi(argv[6]);
   a7 = atoi(argv[7]);
   
   printf("Assignment 1 program was written by Sean Hassan\n");
   printf("inputs: %d %d %d %d %d %d %d\n",
      a1, a2, a3, a4, a5, a6, a7);
   
   mxsz = a2+a3+a4+a5+a6+a7;
   
   if ((s1 = malloc(mxsz)) == NULL || (s2 = malloc(mxsz)) == NULL) {
      printf("Not enough memory\n");
      exit(2);
   }
   
   heading = "Part 1\n";
   
   fcfsa(s1, s2, a2, a3, a4, a5, a6, a7);
   display(heading, s1, s2);
   
   return 0;
}
