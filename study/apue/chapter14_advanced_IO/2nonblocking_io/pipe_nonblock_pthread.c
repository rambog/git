#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>


static void *
thr_read(void *arg)
{
    int rfd = *((int*)arg);
    char tmp[128];
    int err;

    int status = fcntl(rfd, F_GETFL);
    status |= O_NONBLOCK;
    fcntl(rfd, F_SETFL, status);

    usleep(1000);
    err = read(rfd, tmp, sizeof(tmp));
    if (err < 0)
        perror("read err");
    else
        printf("%s", tmp);
}

static void *
thr_write(void *arg)
{
    int wfd = *((int*)arg);
    char tmp[128];
    int err;

    memset(tmp, 0x00, sizeof(tmp));
    sprintf(tmp, "%s", "I am rambo\n");

#if 0
    int status, cyc;
    status = fcntl(wfd, F_GETFL);
    status |= O_NONBLOCK;
    fcntl(wfd, F_SETFL, status);

    cyc = 0;
    while (1) {
        err = write(wfd, tmp, strlen(tmp));
        cyc++;
        if (err < 0) {
            perror("write pipe err");
            break;
        }
    }

    printf("total cyc : %d\n", cyc);
#else
#if 1
    if (strlen(tmp) == write(wfd, tmp, strlen(tmp)))
        printf("write pipe complete\n");
    else 
        perror("write pipe err");
#endif
#endif
}

int
main(void)
{
    pthread_t rtid, wtid;
    int pipefd[2];
    int err;

    err = pipe(pipefd);
    if (err != 0) perror("pipe err");

    pthread_create(&rtid, NULL, thr_read, (void*)&pipefd[0]);
    pthread_create(&wtid, NULL, thr_write, (void*)&pipefd[1]);

    pthread_join(rtid, NULL);
    pthread_join(wtid, NULL);

    return 0;
}
