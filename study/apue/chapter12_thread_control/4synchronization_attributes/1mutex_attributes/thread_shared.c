#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>
#include <errno.h>

int
main(void)
{
    printf("_SC_THREAD_PROCESS_SHARED : %d\n", sysconf(_SC_THREAD_PROCESS_SHARED));
    return 0;
}
