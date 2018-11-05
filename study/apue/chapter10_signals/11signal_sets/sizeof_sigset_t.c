#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>
#include <setjmp.h>

int
main(int argc, char *argv[])
{ 
    sigset_t sigs;

    printf("sizeof sigset_t : %u\n", sizeof(sigset_t));
    printf("sizeof sigset_t val : %u\n", sizeof(sigs));
    printf("sizeof int : %u\n", sizeof(int));
    printf("sizeof jmp_buf : %u\n", sizeof(jmp_buf));
    printf("sizeof unsigned long ing : %u\n", sizeof(unsigned long int));

    return 0;
}
