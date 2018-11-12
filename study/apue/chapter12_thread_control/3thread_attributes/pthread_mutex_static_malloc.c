#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>
#include <errno.h>

static pthread_mutex_t global_lock = PTHREAD_MUTEX_INITIALIZER;

int
main(void)
{
    static pthread_mutex_t static_lock;
    auto pthread_mutex_t auto_lock;
    pthread_mutex_t *pmalloc_lock;
    pmalloc_lock = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
    if (pmalloc_lock == NULL) return 0;

    int err;

    err = pthread_mutex_lock(&global_lock);
    if (err != 0) printf("global_lock err : %s\n", strerror(err));

#if 0
    err = pthread_mutex_lock(&auto_lock);
    if (err != 0) printf("auto_lock err : %s\n", strerror(err));

    err = pthread_mutex_lock(&static_lock);
    if (err != 0) printf("static_lock err : %s\n", strerror(err));
#endif

    err = pthread_mutex_lock(pmalloc_lock);
    if (err != 0) printf("pmalloc_loc err : %s\n", strerror(err));

    return 0;
}
