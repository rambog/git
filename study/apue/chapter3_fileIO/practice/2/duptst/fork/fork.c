#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int
main(int argc, char *argv[], char *envp[])
{
    if (argc != 2) {
        printf("usage : %s <file>\n", argv[0]);
        return 0;
    }

    int fdo, fdb;

    fdo = open(argv[1], O_RDWR|O_CREAT, S_IRWXU);
    int fdstatus = fcntl(fdo, F_GETFD);
    fdstatus |= FD_CLOEXEC;
    fcntl(fdo, F_SETFD, fdstatus);

    fdb = dup(fdo);

    pid_t pid;

    pid = fork();

    char buf[128];

    if (pid < 0) {
        return 0;
    } else if (pid == 0) {
       memset(buf, 0x00, sizeof(buf)); 
       sprintf(buf, "child proc : i am fdo\n");
       write(fdo, buf, strlen(buf));

       memset(buf, 0x00, sizeof(buf)); 
       sprintf(buf, "child proc : i am fdb\n");
       write(fdb, buf, strlen(buf));

        char afdo[8];
        char afdb[8];
        sprintf(afdo, "%d", fdo);
        sprintf(afdb, "%d", fdb);
        printf("%s %s\n", afdo, afdb);
        if (-1 == execl("./test", "test", afdo, afdb, NULL)) {
            printf("execl err[%d], %m\n", errno);
        }
    } else {
        memset(buf, 0x00, sizeof(buf)); 
        sprintf(buf, "parent proc : i am fdo\n");
       write(fdo, buf, strlen(buf));

       memset(buf, 0x00, sizeof(buf)); 
       sprintf(buf, "parent proc : i am fdb\n");
       write(fdb, buf, strlen(buf));
    }

    return 0;
}
