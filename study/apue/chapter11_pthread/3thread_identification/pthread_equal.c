#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>

int
main(int argc, char *argv[])
{
    pthread_t tid1=1, tid2=2;

    tid1 = pthread_self();
    tid2 = pthread_self();

    printf("tid1:%lu, tid2:%lu %m\n", tid1, tid2);

    if (pthread_equal(tid1, tid2))
        printf("tid1 == tid2\n");
    else
        printf("tid1 != tid2\n");

    return 0;
}
