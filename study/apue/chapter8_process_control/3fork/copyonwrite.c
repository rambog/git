#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

unsigned int cyctick = 0;
unsigned char flag = 0;

void *
thr_func(void *arg)
{
    printf("enter thr_func:%lu\n", pthread_self());

    for ( ; ; ) {
        if (!flag) continue;

        printf("thr_func cyc[%u]\n", cyctick);
        cyctick++;
        sleep(1);
    }
}

int
main()
{
    pthread_t tid;
    if (pthread_create(&tid, NULL, thr_func, NULL) < 0) {
        perror("pthread_create");
        return 0;
    }
    usleep(100*1000);

    pid_t pid;

    pid = fork();
    if (pid < 0) {
        perror("fork");
        return 0;
    } else if (pid == 0) {
        printf("i am child\n");
        flag = 1;

        while (1)
            pause();
        exit(0);
    }

    flag = 1;

    for ( ; ; )
        pause();

    return 0;
}
