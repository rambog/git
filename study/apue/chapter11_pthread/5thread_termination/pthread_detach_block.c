#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>

static void *
thr_fn(void *arg)
{
    //pthread_detach(pthread_self());
    sleep(1);
    
    printf("thread exit\n");
    return NULL;
}

int
main(int argc, char *argv[])
{
    pthread_t tid;
    int err;

    err = pthread_create(&tid, NULL, thr_fn, NULL);
    if (err != 0) {
        printf("pthreadcreat err : %s\n", strerror(err));
        return 0;
    }

    sleep(1);
    err = pthread_join(tid, NULL);
    if (err != 0) {
        printf("pthread_join err : %s\n", strerror(err));
    }

    printf("pthread_join exit\n");

    return 0;
}
