#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int
mydup2(int fd, int fd2)
{
   if (fd2 < 0) {
       errno = -9;
       return -1;
   }

   struct stat sbuf;
   if (-1 == fstat(fd, &sbuf)) {
       return -1;
   }

   
}
