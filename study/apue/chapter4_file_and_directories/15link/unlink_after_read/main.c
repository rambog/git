#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int
main(int argc, char *argv[], char *envp[])
{
   if (argc != 2) {
       printf("usage : %s <file>\n", argv[0]);
       return 1;
   }

   int fd;
   
   fd = open(argv[1], O_RDWR);
   if (fd < 0) {
       printf("open err : %m\n");
       return 1;
   }

   unlink(argv[1]);

   ssize_t sread, swrite;
   char buf[16];
   memset(buf, 0x00, sizeof(buf));
   sprintf(buf, "%s", "I am rambo\n");

    #if 0
   swrite = write(fd, buf, strlen(buf));
   if (swrite != strlen(buf)) {
       printf("write err : %m\n");
       return 1;
   }
    #endif

   memset(buf, 0x00, sizeof(buf));

    sread = read(fd, buf, sizeof(buf));
    if (sread < 0) {
        printf("read err : %m\n");
        return 1;
    }

    printf("buf read : %s\n", buf);

    exit(0);
}
