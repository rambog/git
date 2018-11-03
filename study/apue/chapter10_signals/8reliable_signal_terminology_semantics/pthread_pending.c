#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <pthread.h>

static pid_t pid;

static void
sig_intr(int signo)
{
    if (signo == SIGINT) {
        printf("I am tid:%lu, get sigintr!\n", getpid());
        sleep(3);
    }
}

static void
sig_quit(int signo)
{
    if (signo == SIGQUIT) {
        printf("I am tid:%lu, get sigquit!\n", getpid());
    }
}

static void *
thr_func(void *arg)
{
    printf("I am thread:%lu, send sigint\n", pthread_self());

    kill(pid, SIGINT);
    kill(pid, SIGUSR1);

    printf("I am thread:%lu, send sigint finish\n", pthread_self());

    pthread_exit(NULL);
}

int
main(int argc, char *argv[])
{
    pid = fork();
    if (pid < 0) {
        return 0;
    } else if (pid == 0) {
        signal(SIGINT, sig_intr);
        signal(SIGUSR1, sig_intr);

        printf("I am child : %lu\n", getpid());

        while (1)
            pause();

        return 0;
    }
    sleep(1);

    pthread_t tid[4];
    int i = 0;

    for (i = 0; i < sizeof(tid)/sizeof(tid[0]); i++) {
        pthread_create(&tid[i], NULL, thr_func, NULL);
    }

    //kill(pid, SIGINT);

    while (1) {
        pause();
    }

    return 0;
}
