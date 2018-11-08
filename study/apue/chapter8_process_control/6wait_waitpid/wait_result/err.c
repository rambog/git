#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/wait.h>

int
main(void)
{
    if (wait(NULL) < 0) {
        perror("wait err");
        return 1;
    }

    return 0;
}
