#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <errno.h>
#include <pthread.h>

void *
thr_detach(void *arg)
{
    sleep(1);
    pthread_exit(PTHREAD_CANCELED);
}

void *
thr_join(void *arg)
{
    sleep(1);
    pthread_exit(PTHREAD_CANCELED);
}

int
main(void)
{
    pthread_t dettid, joitid;
    pthread_attr_t detattr, joiattr;
    int err;

    err = pthread_attr_init(&detattr);
    if (err != 0) printf("pthread_attr_init err: %s\n", strerror(err));

    err = pthread_attr_init(&joiattr);
    if (err != 0) printf("pthread_attr_init err: %s\n", strerror(err));

    /* PTHREAD_CREATE_DETACHED */
    /* PTHREAD_CREATE_JOINABLE */

    int detachstate;

    detachstate = PTHREAD_CREATE_DETACHED;
    err = pthread_attr_setdetachstate(&detattr, detachstate);
    if (err != 0) printf("pthread_attr_setdetachstate err : %s\n", strerror(err));

    detachstate = PTHREAD_CREATE_JOINABLE;
    err = pthread_attr_setdetachstate(&joiattr, detachstate);
    if (err != 0) printf("pthread_attr_setdetachstate err : %s\n", strerror(err));

    err = pthread_create(&dettid, &detattr, thr_detach, NULL);
    if (err != 0) printf("pthread_create err : %s\n", strerror(err));

    err = pthread_create(&joitid, &joiattr, thr_join, NULL);
    if (err != 0) printf("pthread_create err : %s\n", strerror(err));

    err = pthread_attr_destroy(&detattr);
    if (err != 0) printf("pthread_attr_destroy err : %s\n", strerror(err));

    err = pthread_attr_destroy(&joiattr);
    if (err != 0) printf("pthread_attr_destroy err : %s\n", strerror(err));


    err = pthread_join(dettid, NULL);
    if (err != 0) printf("pthread_join dettid err : %s\n", strerror(err));

    err = pthread_join(joitid, NULL);
    if (err != 0) printf("pthread_join joitid err : %s\n", strerror(err));

    return 0;
}
