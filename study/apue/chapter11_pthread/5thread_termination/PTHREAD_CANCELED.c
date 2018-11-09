#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static void *
thr_fn(void *arg)
{
    return PTHREAD_CANCELED;
}

int
main(void)
{
    if (NULL == PTHREAD_CANCELED) {
        printf("NULL == PTHREAD_CANCELED\n");
    } else {
        printf("PTHREAD_CANCELED : %p, NULL : %p\n", PTHREAD_CANCELED, NULL);
    }

    pthread_t tid;
    int err;

    err = pthread_create(&tid, NULL, thr_fn, NULL);
    if (err != 0) {
        printf("pthread_create err : %s\n", strerror(err));
        return 0;
    }

    void *pret;

    err = pthread_join(tid, &pret);
    if (err != 0) {
        printf("pthread_join err : %s\n", strerror(err));
        return 0;
    }

    printf("thread ret : %p\n", pret);

    return 0;
}
