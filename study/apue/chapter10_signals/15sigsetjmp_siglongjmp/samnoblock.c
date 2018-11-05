#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <setjmp.h>

static jmp_buf jmp_env;

static void
sig_intr(int signo)
{
    if (signo == SIGINT) {
        printf("SIGINT starting\n");

        sleep(1);

        printf("SIGINT finished\n");
    }
}

int
main(int argc, char *argv[])
{
#if 0
    if (signal(SIGINT, sig_intr) == SIG_ERR) {
        perror("signal SIGINT");
        return 0;
    }
#else
    struct sigaction sigac;

    sigac.sa_flags = 0;
    sigemptyset(&sigac.sa_mask);
    sigac.sa_handler = sig_intr;
    sigac.sa_flags |= SA_NODEFER;
    if (sigaction(SIGINT, &sigac, NULL) < 0) {
        perror("sigaction SIgINT err");
        return 0;
    }
#endif

    if (setjmp(jmp_env) == 0) {
        printf("init\n");
    }

    for ( ; ; ) pause();

    return 0;
}
