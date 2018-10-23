#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int
main(int argc, char *argv[], char *envp[])
{
    if (argc != 2) {
        printf("usage : %s <dir>\n", argv[0]);
        return 1;
    }

    char *file1 = "file1.txt";
    char *file2 = "file2.txt";
    char *file3 = "file3.txt";

    char filename[64];
    memset(filename, 0x00, sizeof(filename));

    int sysret;
    sysret = mkdir(argv[1], S_IRWXU|S_IRWXG|S_IRWXO);
    if (sysret == -1) {
        printf("mkdir err[%d] : %m\n", errno);
        return 1;
    }

    int fd_tmp;

    sprintf(filename, "%s/%s", argv[1], file1);
    fd_tmp = open(filename, O_RDWR|O_CREAT|O_EXCL, 0000);
    if (fd_tmp < 0) {
        printf("%s open err[%d] : %m\n", filename, errno);
    }
    sysret = write(fd_tmp, filename, strlen(filename));
    if (sysret < 0) {
        printf("%s wiret err[%d] : %m\n", filename, errno);
    }
    memset(filename, 0x00, sizeof(filename));
    lseek(fd_tmp, 0, SEEK_SET);
    sysret = read(fd_tmp, filename, sizeof(filename));
    if (sysret < 0) {
        printf("read err[%d] : %m\n", errno);
    }
    printf("read some data: %s\n", filename);
    
    sprintf(filename, "%s/%s", argv[1], file2);
    fd_tmp = open(filename, O_RDWR|O_CREAT|O_EXCL, 0000);
    if (fd_tmp < 0) {
        printf("%s open err[%d] : %m\n", filename, errno);
    }
    sysret = write(fd_tmp, filename, strlen(filename));
    if (sysret < 0) {
        printf("%s wiret err[%d] : %m\n", filename, errno);
    }
    memset(filename, 0x00, sizeof(filename));
    lseek(fd_tmp, 0, SEEK_SET);
    sysret = read(fd_tmp, filename, sizeof(filename));
    if (sysret < 0) {
        printf("read err[%d] : %m\n", errno);
    }
    printf("read some data: %s\n", filename);

    sprintf(filename, "%s/%s", argv[1], file3);
    fd_tmp = open(filename, O_RDWR|O_CREAT|O_EXCL, 0000);
    if (fd_tmp < 0) {
        printf("%s open err[%d] : %m\n", filename, errno);
    }
    sysret = write(fd_tmp, filename, strlen(filename));
    if (sysret < 0) {
        printf("%s wiret err[%d] : %m\n", filename, errno);
    }
    memset(filename, 0x00, sizeof(filename));
    lseek(fd_tmp, 0, SEEK_SET);
    sysret = read(fd_tmp, filename, sizeof(filename));
    if (sysret < 0) {
        printf("read err[%d] : %m\n", errno);
    }
    printf("read some data: %s\n", filename);

    #if 0
    sysret = rmdir(argv[1]);
    if (sysret < 0) {
        printf("rmdir %s err[%d] : %m\n", argv[1], errno);
    }
    #endif

    exit(0);
}
