#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "myio.h"

int checkInt(char *arg);

int main(int argc, char *argv[]) {
   int doubles, i, ints, lines;
   char newline;
   FILE *out;
   int x, y, z;
   
   newline = '\n';
   
   if (argc != 5) {
      printf("Usage is x y z output_filename\n");
      return 0;
   }
   
   if (checkInt(argv[1]) != 0)
      return 0;
   ints = atoi(argv[1]);
   if (checkInt(argv[2]) != 0)
      return 0;
   doubles = atoi(argv[2]);
   if (checkInt(argv[3]) != 0)
      return 0;
   lines = atoi(argv[3]);
   
   out = fopen(argv[4], "a");
   if (out == NULL) {
      perror("File could not be opened");
      return 0;
   }
   
   for (x = 0; x < ints; x++) {
      int n = ReadInteger();
      printf("%d\n", n);
      fprintf(out, "%d\n", n);
   }
   
   for (y = 0; y < doubles; y++) {
      double d = ReadDouble();
      printf("%lf\n", d);
      fprintf(out, "%lf\n", d);
   }
   
   for (z = 0; z < lines; z++) {
      char *l = ReadLine();
      printf("%s\n", l);
      fprintf(out, "%s\n", l);
      free(l);
   }

   fclose(out);
   
   return 0;
}

int checkInt(char *arg) {
   int x;
   x = 0;
   
   while (arg[x] != '\0') {
      if (arg[x] > '9' || arg[x] < '0') {
         printf("Improper input. x, y, and z must be ints.\n");
         return -1;
      }
      x++;
   }
   
   return 0;
}
