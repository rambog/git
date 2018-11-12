#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int
main(void)
{
    printf("PTHREAD_DESTRUCTOR_ITERATIONS : %u\n", sysconf(_SC_THREAD_DESTRUCTOR_ITERATIONS));
    printf("PTHREAD_KEYS_MAX : %u\n", sysconf(_SC_THREAD_KEYS_MAX));
    printf("PTHREAD_STACK_MIN : %u\n", sysconf(_SC_THREAD_STACK_MIN));
    printf("PTHREAD_THREADS_MAX : %u\n", sysconf(_SC_THREAD_THREADS_MAX));

    return 0;
}
