#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

static void sig_handler(int );

int
main(int argc, char *argv[])
{
    printf("in point way SIG_ERR: %p\n", SIG_ERR);
    printf("in point way SIG_DFL: %p\n", SIG_DFL);
    printf("in point way SIG_IGN: %p\n", SIG_IGN);
    
    printf("in unsigned way SIG_ERR: %u\n", SIG_ERR);
    printf("in unsigned way SIG_DFL: %u\n", SIG_DFL);
    printf("in unsigned way SIG_IGN: %u\n", SIG_IGN);

    printf("in signed way SIG_ERR: %d\n", SIG_ERR);
    printf("in signed way SIG_DFL: %d\n", SIG_DFL);
    printf("in signed way SIG_IGN: %d\n", SIG_IGN);

    void (*sig_ret)(int);

    sig_ret = signal(SIGINT, sig_handler);
    if (sig_ret == SIG_IGN)
        printf("SIGINT orignal is SIG_IGN\n");
    else if (sig_ret == SIG_DFL)
        printf("SIGDFL orignal is SIG_DFL\n");
    else if (sig_ret == SIG_ERR)
        printf("SIGDFL orignal is SIG_ERR\n");
    else 
        signal(SIGINT, sig_ret);


    if (SIG_IGN == signal(SIGQUIT, sig_handler))
        printf("SIGQUIT orignal is SIG_IGN\n");

    if (SIG_IGN == signal(SIGTSTP, sig_handler))
        printf("SIGTSTP orignal is SIG_IGN\n");

    return 0;
}

static void sig_handler(int signo)
{
    switch (signo) {
        default :
            return;
    }
}
