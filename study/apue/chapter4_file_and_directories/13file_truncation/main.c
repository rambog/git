#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FILEMOD (S_IRUSR|S_IXUSR|S_IWUSR|S_ISUID|S_IRGRP|S_IWGRP|S_IXGRP|S_ISGID|S_IROTH|S_IWOTH|S_IXOTH)

int
main(int argc, char *argv[], char *envp[])
{
    if (argc != 2) {
        printf("usage : %s <file>\n", argv[0]);
        return 1;
    }

    int sysret;

    sysret = unlink(argv[1]);
    if (sysret < 0) {
        printf("unlink err : %m\n");
    }

    int fd = 0;
    fd = open(argv[1], O_RDWR|O_CREAT|O_EXCL, FILEMOD);
    if (fd < 0) {
        printf("open err : %m\n");
        return 1;
    }

    ssize_t sread, swrite;
    unsigned char buf[4096] = {0x9F};
    memset(buf, 0x9F, sizeof(buf));

    swrite = write(fd, buf, sizeof(buf));
    if (swrite != sizeof(buf)) {
        printf("write err : %m\n");
        return 1;
    }

    struct stat statbuf;

    sysret = fstat(fd, &statbuf);
    if (sysret < 0) {
        printf("fstat err : %m\n");
        return 1;
    }
    
    printf("file size : %d\n", statbuf.st_size);

    sysret = ftruncate(fd, 4096*20);
    if (sysret < 0) {
        printf("ftruncate err : %m\n");
        return 1;
    }

    sysret = fstat(fd, &statbuf);
    if (sysret < 0) {
        printf("fstat err : %m\n");
        return 1;
    }
    
    printf("after ftruncate file size : %d\n", statbuf.st_size);

    int i = 0;
    int readcnt = 0;

    lseek(fd, 0, SEEK_SET);
    while ((sread = read(fd, buf, sizeof(buf))) > 0) {
        readcnt++;
        printf("read cyc : %d\n", readcnt);
    }

    exit(0);
}
