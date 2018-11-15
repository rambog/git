#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>

void
sig_intr(int signo)
{
    printf("%ld enter SIGINT handler\n", (long)getpid());
}

int
main(void)
{
    int pipefd[2];
    int err;

    err = pipe(pipefd);
    if (err != 0) perror("pipe err");

    struct sigaction intr_sa;
    sigemptyset(&intr_sa.sa_mask);
    intr_sa.sa_handler = sig_intr;
    intr_sa.sa_flags = 0;
    intr_sa.sa_flags |= SA_INTERRUPT;
    err = sigaction(SIGUSR1 , &intr_sa, NULL);
    if (err != 0) perror("sigaction SIGINT err");

    pid_t pid;
    pid = fork();
    if (pid == 0) {
        printf("I am child pid:%ld\n", (long)getpid());
        sleep(3);
        pid_t father = getppid();
        char *tmp = "I am child\n";
        write(pipefd[1], tmp, strlen(tmp));
        kill(father, SIGUSR1);
        write(pipefd[1], tmp, strlen(tmp));
        while (1) pause();
        exit(1);
    }

    printf("I am father pid:%ld\n", (long)getpid());
    char tmp[128];
    ssize_t readn;
    memset(tmp, 0x00, sizeof(tmp));

#if 0
    int status = fcntl(pipefd[0], F_GETFL);
    status |= O_NONBLOCK;
    fcntl(pipefd[0], F_SETFL, status);
#endif

    while (1) {
        readn = read(pipefd[0], tmp, sizeof(tmp));
        if (readn < 0 && errno != EAGAIN)
            perror("read err");
        else if (readn < sizeof(tmp) && readn > 0)
            printf("read not enough : %s\n", tmp);
        else if (readn == sizeof(tmp))
            printf("readn : %d readtxt:%s\n", readn, tmp);
    }
    printf("recv from pipe : %s\n", tmp);

    waitpid(pid, NULL, 0);

    return 0;
}
