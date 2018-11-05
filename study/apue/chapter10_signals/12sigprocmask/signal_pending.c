#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>

void sig_intr(int signo)
{
    if (signo == SIGINT) {
        printf("get sigintr\n");
        sleep(2);
        printf("deal sigint end\n");
    }
}

int
main(int argc, char *argv[])
{
    signal(SIGINT, sig_intr);

    sigset_t sigmask;

    sigprocmask(SIG_BLOCK, NULL, &sigmask);
    sigaddset(&sigmask, SIGINT);
    sigprocmask(SIG_BLOCK, &sigmask, NULL);

    raise(SIGINT);
    //raise(SIGINT);
    //raise(SIGINT);
    printf("raise SIGINT finish!\n");
    
    //sleep(3);

    sigdelset(&sigmask, SIGINT);
    sigprocmask(SIG_UNBLOCK, &sigmask, NULL);

    //while(1) pause();

    return 0;
}
