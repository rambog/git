#include <stdio.h>
#include <stdlib.h>

#include <errno.h>
#include <unistd.h>

static void my_exit1(void);
static void my_exit2(void);

int
main(void)
{
    if (atexit(my_exit2) != 0) 
        return 0;

    if (atexit(my_exit1) != 0)
        return 0;

    if (atexit(my_exit1) != 0)
        return 0;

    printf("main is done\n");

    return 0;
}

static void
my_exit1(void)
{
    printf("first exit handler\n");
}

static void
my_exit2(void)
{
    printf("second exit handler\n");
}
