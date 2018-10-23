#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>

int
main(int argc, char *argv[], char *envp[])
{
    if (argc != 2) {
        printf("usage : %s <file>\n", argv[0]);
        return 0;
    }

    struct stat statbuf;
    int sysret;

    /* first stat */
    sysret = stat(argv[1], &statbuf);
    if (sysret == -1) {
        printf("stat err[%d] : %m\n", errno);
        return 1;
    }

    printf("st_atime : tv_sec:%u\n", statbuf.st_atime);
    printf("st_mtime : tv_sec:%u\n", statbuf.st_mtime);
    printf("st_ctime : tv_sec:%u\n\n", statbuf.st_ctime);


    /* open stat */
    int fd = open(argv[1], O_RDWR);
    if (fd < 0) {
        printf("open err[%d] : %m\n", errno);
        return 1;
    }

    sysret = stat(argv[1], &statbuf);
    if (sysret == -1) {
        printf("stat err[%d] : %m\n", errno);
        return 1;
    }

    printf("open st_atime : tv_sec:%u\n", statbuf.st_atime);
    printf("open st_mtime : tv_sec:%u\n", statbuf.st_mtime);
    printf("open st_ctime : tv_sec:%u\n\n", statbuf.st_ctime);

    #if 0
    /* lseek stat */
    sysret = lseek(fd, 1024, SEEK_SET);
    if (sysret == -1) {
        printf("lseek err[%d] : %m\n", errno);
        return 1;
    }

    sysret = stat(argv[1], &statbuf);
    if (sysret == -1) {
        printf("stat err[%d] : %m\n", errno);
        return 1;
    }

    printf("leek st_atime : tv_sec:%u\n", statbuf.st_atime);
    printf("leek st_mtime : tv_sec:%u\n", statbuf.st_mtime);
    printf("leek st_ctime : tv_sec:%u\n\n", statbuf.st_ctime);
    #endif

    char buf[64];
    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "%s", "i am rambo");

    /* write stat */
    sleep(3);
    ssize_t swrite;
    swrite = write(fd, buf, strlen(buf));
    if (swrite < 0) {
        printf("write err[%d] : %m\n", errno);
        return 1;
    }

    sysret = stat(argv[1], &statbuf);
    if (sysret == -1) {
        printf("stat err[%d] : %m\n", errno);
        return 1;
    }

    printf("write st_atime : tv_sec:%u\n", statbuf.st_atime);
    printf("write st_mtime : tv_sec:%u\n", statbuf.st_mtime);
    printf("write st_ctime : tv_sec:%u\n\n", statbuf.st_ctime);

    /* write stat */
    sleep(3);
    swrite = write(fd, buf, strlen(buf));
    if (swrite < 0) {
        printf("write err[%d] : %m\n", errno);
        return 1;
    }

    sysret = stat(argv[1], &statbuf);
    if (sysret == -1) {
        printf("stat err[%d] : %m\n", errno);
        return 1;
    }

    printf("write again st_atime : tv_sec:%u\n", statbuf.st_atime);
    printf("write again st_mtime : tv_sec:%u\n", statbuf.st_mtime);
    printf("write again st_ctime : tv_sec:%u\n\n", statbuf.st_ctime);

    /* write stat */
    sleep(3);
    swrite = write(fd, buf, strlen(buf));
    if (swrite < 0) {
        printf("write err[%d] : %m\n", errno);
        return 1;
    }

    sysret = stat(argv[1], &statbuf);
    if (sysret == -1) {
        printf("stat err[%d] : %m\n", errno);
        return 1;
    }

    printf("write again st_atime : tv_sec:%u\n", statbuf.st_atime);
    printf("write again st_mtime : tv_sec:%u\n", statbuf.st_mtime);
    printf("write again st_ctime : tv_sec:%u\n\n", statbuf.st_ctime);

    /* read stat */
    lseek(fd, 0, SEEK_SET);
    sleep(3);
    ssize_t sread;
    memset(buf, 0x00, sizeof(buf));
    sread = read(fd, buf, sizeof(buf));
    if (sread < 0) {
        printf("read err[%d] : %m\n", errno);
        return 1;
    }

    sysret = stat(argv[1], &statbuf);
    if (sysret == -1) {
        printf("stat err[%d] : %m\n", errno);
        return 1;
    }

    printf("read some data : %s\n", buf);
    printf("read st_atime : tv_sec:%u\n", statbuf.st_atime);
    printf("read st_mtime : tv_sec:%u\n", statbuf.st_mtime);
    printf("read st_ctime : tv_sec:%u\n\n", statbuf.st_ctime);

    /* chmod stat */
    sleep(3);
    sysret = fchmod(fd, statbuf.st_mode|S_IROTH|S_IWOTH|S_IXOTH);     
    if (sysret == -1) {
        printf("chmod err[%d] : %m\n", errno);
        return 1;
    }

    sysret = stat(argv[1], &statbuf);
    if (sysret == -1) {
        printf("stat err[%d] : %m\n", errno);
        return 1;
    }

    printf("chmod st_atime : tv_sec:%u\n", statbuf.st_atime);
    printf("chmod st_mtime : tv_sec:%u\n", statbuf.st_mtime);
    printf("chmod st_ctime : tv_sec:%u\n\n", statbuf.st_ctime);

    exit(0);
}
