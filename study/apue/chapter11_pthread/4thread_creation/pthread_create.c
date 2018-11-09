#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <errno.h>

static void*
thr_func(void *arg)
{
    return NULL;
}

int
main(void)
{
    pthread_t tid;
    int ret;

    //ret = pthread_create(NULL, NULL, NULL, NULL);
    //printf("all null : %s\n", strerror(ret));
    
    //ret = pthread_create(&tid, NULL, NULL, NULL);
    //printf("all null : %s\n", strerror(ret));

    //ret = pthread_create(NULL, NULL, thr_func, NULL);
    //printf("all null : %s\n", strerror(ret));

    return 0;
}
