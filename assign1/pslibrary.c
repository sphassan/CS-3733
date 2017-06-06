#include <stdio.h>
#include <string.h>

void part0(char *s1, char *s2) {
   char *p0str1 = "RRwwwwwRRRRRRRRR";
   char *p0str2 = "rrRRRRwwwwwwwwrrRRRRRRR";
   
   memcpy(s1, p0str1, 17);
   memcpy(s2, p0str2, 24);
   
   return;
}

void display(char *heading, char *s1, char *s2) {
   int length, l1, l2, r1, r2, totR, x;
   
   printf("\n%s", heading);
   printf("%s\n", s1);
   printf("%s\n", s2);
   
   l1 = 0;
   l2 = 0;
   r1 = 0;
   r2 = 0;
   totR = 0;
   
   x = 0;
   while (s1[x] != '\0') {
      if (s1[x] == 'r')
         r1++;
      else if (s1[x] == 'R')
         totR++;
      l1++;
      
      x++;
   }
   
   x = 0;
   while (s2[x] != '\0') {
      if (s2[x] == 'r')
         r2++;
      else if (s2[x] == 'R')
         totR++;
      l2++;
      
      x++;
   }
   
   if (l1 > l2)
      length = l1;
   else
      length = l2;
   
   printf("%d ", r1);
   printf("%d ", r2);
   printf("%.1f ", (double)(r1+r2)/2);
   printf("%.5f\n", (double)totR/length);
}

void insert(char *s, int pos, char rep) {
   int x, len;
   if (s == NULL)
      printf("Passing null to strlen\n");
   len = strlen(s);
   
   for (x = len; x >= pos; x--)
      s[x+1] = s[x];
   s[pos] = rep;
}

void fcfsa(char *s1, char *s2, int x1, int y1, int z1, int x2, int y2, int z2) {
   int x, s1l, s2l;
   
   s1l = x1+y1+z1;
   s2l = x1+x2+y2+z2;
   
   x = 0;
   while (x != -1) {
      if (x1 != 0) {
         s1[x] = 'R';
         s2[x] = 'r';
         
         x1--;
      }
      else {
         if (y1 != 0) {
            s1[x] = 'w';
            y1--;
         }
         else if (z1 != 0) {
            s1[x] = 'R';
            z1--;
         }
         else if (z2 == 0)
            x = -2;
         
         
         if (x2 != 0) {
            s2[x] = 'R';
            x2--;
         }
         else if (y2 != 0) {
            s2[x] = 'w';
            y2--;
         }
         else if (z2 != 0) {
            s2[x] = 'R';
            z2--;
         }
         else if (z1 == 0)
            x = -2;
      }
      
/*      
      if (s1[x] == 'R' && s2[x] == 'R') {
         if (s2[x-1] == s2[x]) {
            s1[x+1] = s1[x];
            s1[x] = 'r';
         }
         else {
            s2[x+1] = s2[x];
            s2[x] = 'r';
         }
      }
*/      
      x++;
   }
   
   s1[s1l] = '\0';
   s2[s2l] = '\0';
   
   x = 0;
   while(s1[x] != '\0' && s2[x] != '\0') {
         if (s1[x] == 'R' && s2[x] == 'R') {
            if (s2[x] == s2[x-1])
               insert(s1, x, 'r');
            else
               insert(s2, x, 'r');
         }
         x++;
     }
}
