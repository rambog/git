#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <signal.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;
pthread_once_t init_done = PTHREAD_ONCE_INIT;
void mutex_printf(char *);

static void
sig_intr(int signo)
{
    mutex_printf("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n");
}

void
init_printf(void)
{
    pthread_mutexattr_t attr;

    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&lock, &attr);
    pthread_mutexattr_destroy(&attr);
}

void 
mutex_printf(char *str)
{
    pthread_once(&init_done, init_printf);

    pthread_mutex_lock(&lock);
    printf("%s", str);
    pthread_mutex_unlock(&lock);
}

int 
main(void)
{
    if (signal(SIGINT, sig_intr) == SIG_ERR) return 0;

    pid_t pid;
    pid = fork();
    if (pid == 0) {
        while (1)
            mutex_printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
        exit(0);
    }

    while (1)
        kill(pid, SIGINT);

    exit(0);
}
