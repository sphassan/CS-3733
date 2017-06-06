#include <sys/stat.h>

int get_filesize(char *path) {
   struct stat statbuf;

   if (stat(path, &statbuf) == -1)
      return -1;
   else
      return (int) statbuf.st_size;
}
