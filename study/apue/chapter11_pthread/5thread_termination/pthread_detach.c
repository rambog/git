#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>

static void *
thr_fn(void *arg)
{
    pthread_detach(pthread_self());
    return NULL;
}

int
main(int argc, char *argv[])
{
    pthread_t tid;
    int err;

    for ( ; ; ) {
        err = pthread_create(&tid, NULL, thr_fn, NULL);
        if (err != 0) {
            printf("pthreadcreat err : %s\n", strerror(err));
            return 0;
        }
    }

    return 0;
}
