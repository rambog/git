#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int
main(void)
{
    int err;
    pthread_mutex_t norlock;
    pthread_mutexattr_t lockattr;

    pthread_mutex_init(&norlock, NULL);
    pthread_mutexattr_init(&lockattr);

    int locktype;

    err = pthread_mutexattr_gettype(&lockattr, &locktype);
    if (err != 0)
        printf("pthread_mutexattr_gettype err : %s\n", strerror(err));

    switch (locktype) {
        case PTHREAD_MUTEX_NORMAL:
            printf("PTHREAD_MUTEX_NORMAL\n");
            break;
        case PTHREAD_MUTEX_ERRORCHECK:
            printf("PTHREAD_MUTEX_ERRORCHECK\n");
            break;
        case PTHREAD_MUTEX_RECURSIVE:
            printf("PTHREAD_MUTEX_RECURSIVE\n");
            break;
        default:
            return 0;
    }

    if (PTHREAD_MUTEX_NORMAL == PTHREAD_MUTEX_DEFAULT)
        printf("normal == default\n");

    return 0;
}
