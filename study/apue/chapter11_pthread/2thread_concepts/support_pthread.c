#include <stdio.h>
#include <unistd.h>

int
main(void)
{
    long result = sysconf(_SC_THREADS);

    printf("support pthread result:%ld\n", result);

#ifdef _POSIX_THREADS
    printf("macro pthread define : %ld\n", _POSIX_THREADS);
#endif

    return 0;
}
