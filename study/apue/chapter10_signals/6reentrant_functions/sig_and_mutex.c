#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>
#include <pthread.h>

pthread_mutex_t pm;

static void
sig_func(int signo)
{
    switch (signo) {
        case SIGINT:
            pthread_mutex_lock(&pm);
            pthread_mutex_unlock(&pm);
            break;
        case SIGQUIT:
            exit(0);
            break;
        case SIGTSTP:
            break;
        default:
            return;
    }
}

int
main(int argc, char *argv[])
{
    signal(SIGINT, sig_func);
    signal(SIGQUIT,sig_func);
    signal(SIGTSTP,sig_func);

    pthread_mutex_init(&pm, NULL);

    pthread_mutex_lock(&pm);

    raise(SIGINT);

    pthread_mutex_unlock(&pm);
}
