#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void
out1(void)
{
    printf("i am out1\n");
}

void
out2(void)
{
    printf("i am out2\n");
}

void
out3(void)
{
    printf("i am out3\n");
}

void
sig_intr(int signo)
{
    printf("sigintr handler\n");
    exit(0);
}

void
main(int argc, char *argv[])
{
    atexit(out1);
    atexit(out2);
    atexit(out3);

    signal(SIGINT, sig_intr);

    //_exit(0);
    
    for ( ; ; )
        pause();
}
