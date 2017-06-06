#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *ReadInput(int fd) {
   char buf[BUFSIZ];
   int i;
   char *input;
   int r, ret, x;
   
   i = 1;
   r = 0;
   ret = 1;
   
   input = calloc(BUFSIZ, sizeof(char));
   
   while (ret > 0) {
      ret = read(fd, &buf, BUFSIZ);
      
      for (x = 0; x < BUFSIZ; x++) {
         if (buf[x] == '\n' || buf[x] == EOF) {
            ret = -1;
            break;
         }
         input[x*i] = buf[x];
         r++;
      }
      
      i++;
      
      if (ret != -1)
         input = realloc(input, BUFSIZ*i);
   }
   
   if (r == 0)
      return NULL;
   
   input[r] = '\0';
   input = realloc(input, r+1);
   
   return(input);
}

int ReadInteger() {
   char *input;
   int go, num, x;
   go = 0;
   
   do {
      go = 0;
      
      printf("Input an integer\n");
      input = ReadInput(STDIN_FILENO);
      for (x = 0; x < INT_MAX; x++) {
         if (x == 0 && input[x] == '-')
            continue;
         if (input[x] == 0)
            break;
         else if (input[x] > '9' || input[x] < '0') {
            go = 1;
            printf("Improper input\n");
            break;
         }
     }
   } while (go == 1);
   
   num = atoi(input);
   free(input);
   
   return num;
}

double ReadDouble(void) {
   int dec, exp;
   char *input;
   int go;
   double num;
   int x;
   
   do {
      go = 0;
      dec = 0;
      exp = 0;
      
      printf("Input a double\n");
      input = ReadInput(STDIN_FILENO);
      for (x = 0; x < INT_MAX; x++) {
         if (x == 0 && input[x] == '-')
            continue;
         if (input[x] == 0)
            break;
         else if (input[x] == '.' && dec == 0)
            dec = 1;
         else if (x != 0 && (input[x] == 'e' || input[x] == 'E') && exp == 0) {
            dec = 1;
            exp = 1;
         }
         else if (input[x] > '9' || input[x] < '0') {
            go = 1;
            printf("Improper input\n");
            break;
         }
      }
   } while (go == 1);
   
   num = strtod(input, NULL);
   free(input);
   
   return num;
}

char *ReadLine(void) {
   printf("Input a line\n");
   return(ReadInput(STDIN_FILENO));
}

char *ReadLineFile(FILE *infile) {
   int fd;
   
   fd = fileno(infile);
   
   return(ReadInput(fd));
}
