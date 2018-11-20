#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <errno.h>

int
main(void)
{
    char foostr[] = "I am rambo\n";
    char buf[sizeof(foostr)];
    int pipefd[2];

    if (0 != pipe(pipefd)) {
        perror("pipe err");
        return 0;
    }

    if (write(pipefd[0], foostr, strlen(foostr)) < 0)
        perror("write pipe err");

    if (read(pipefd[1], buf, sizeof(buf)) < 0)
        perror("read pipe err");

    return 0;
}
