#include <stdio.h>
#include <unistd.h>

int
main(void)
{
    printf("pipe_buf : %d\n", pathconf("./", _PC_PIPE_BUF));

    return 0;
}
