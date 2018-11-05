#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>

int comma_opr(int *argv, int val)
{
    return ((*argv = val) , 0);
}

int
main(int argc, char *argv[])
{
    unsigned int foo = ~(unsigned int)0;
    unsigned int ret = ~(unsigned int)0;

    printf("foo : %u, ret : %u\n", foo, ret);

    ret = comma_opr(&foo, 1);

    printf("foo : %u, ret : %u\n", foo ,ret);

    return 0;
}
