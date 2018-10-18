#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>

static int fd = 0;

void *
thr_tst(void *arg)
{
    int cur = 1000;
    for ( ; cur-- > 0; ) {
        write(fd, arg, strlen((char *)arg));
        usleep(100);
    }
}

int 
main(void)
{
   pthread_t tid1, tid2;

   fd = open("file.txt", O_RDWR|O_CREAT|O_EXCL, 777);
   if (fd < 0) return;

   pthread_create(&tid1, NULL, thr_tst, (void*)"ramboramborambo ");

   pthread_create(&tid2, NULL, thr_tst, (void*)"guiyaoguiyaoguiyao ");


    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    exit(0);
}
