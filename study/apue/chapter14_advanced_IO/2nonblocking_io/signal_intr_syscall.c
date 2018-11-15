#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>

static void 
sig_intr(int signo)
{
    printf("enter SIGINT handler\n");
}

static void
sig_quit(int signo)
{
    printf("enter SIGQUIT handler\n");
}

static void
sig_tstp(int signo)
{
    printf("enter SIGTSTP handler\n");
    exit(0);
}

int
main(void)
{
    char foo[128];

    struct sigaction intr_ac, quit_ac, tstp_ac;

    intr_ac.sa_handler = sig_intr;
    sigemptyset(&intr_ac.sa_mask);
    intr_ac.sa_flags = 0;
    intr_ac.sa_flags |= SA_INTERRUPT;
    if (sigaction(SIGINT, &intr_ac, NULL) != 0)
        perror("sigaction SIGINT err");

    if (signal(SIGQUIT, &sig_quit) != 0)
        perror("signal SIGQUIT err");

    
    if (signal(SIGTSTP, &sig_tstp) != 0)
        perror("signal SIGTSTP err");

#if 0
    int status;
    status = fcntl(STDIN_FILENO, F_GETFL);
    status |= O_NONBLOCK;
    fcntl(STDIN_FILENO, F_SETFL, status);
#endif

    int err;
    memset(foo, 0x00, sizeof(foo));
    while (err = read(STDIN_FILENO, foo, sizeof(foo))) {
        if (err < 0) {
            if (errno == EINTR) {
                printf("read was interrupted\n");
                printf("read txt : %s\n", foo);
            }
            else
                perror("read err");
        }
        else
            printf("read txt : %s\n", foo);
    }

    return 0;
}
