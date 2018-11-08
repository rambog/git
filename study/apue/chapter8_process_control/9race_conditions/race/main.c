#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>

static void charatatime(char *);

int
main(void)
{
    pid_t pid;
    TELL_WAIT();

    if ((pid = fork()) < 0) {
        perror("fork err");
        return 0;
    } else if (pid == 0) {
        WAIT_PARENT();
        charatatime("output from child\n");
    } else {
        charatatime("output from parent\n");
        TELL_CHILD(pid);
    }

    exit(0);
}

static void
charatatime(char *str)
{
    char *ptr;
    int c;

    setbuf(stdout, NULL);
    for (ptr = str; (c = *ptr++) != 0x00; ) {
        putc(c, stdout);
        usleep(100);
    }
}
