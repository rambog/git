#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/mman.h>
#include <signal.h>
#include <fcntl.h>

void
sig_segv(int signo)
{
    printf("tigger sig_segv\n");
    exit(0);
}

void
sig_bus(int signo)
{
    printf("trigger sig_bus\n");
    exit(0);
}

int
main(void)
{
    if (signal(SIGSEGV, sig_segv) == SIG_ERR) exit(0);
    if (signal(SIGBUS, sig_bus) == SIG_ERR) exit(0);

    int fd = open("tmp.txt", O_RDWR|O_CREAT, S_IRWXU);
    if (fd < 0) exit(0);

    void *fdmap = NULL;

    fdmap = mmap(NULL, 16, PROT_READ, MAP_SHARED, fd, 0);
    if (fdmap == MAP_FAILED) perror("mmap err");

    sprintf(fdmap, "%s", "I am rambo\n");

    return 0;
}
