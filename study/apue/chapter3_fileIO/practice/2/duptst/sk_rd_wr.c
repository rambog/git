#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

int
main(int argc, char *argv[], char *envp[])
{
    if (argc != 2) {
        printf("usage : %s <file>\n", argv[0]);
        return 0;
    }

    int fd = open(argv[1], O_RDWR|O_CREAT, S_IRWXU);
    if (fd < 0) {
        printf("open err[%d] : %m\n", argv[1]);
        return 0;
    }

    int fdb = dup(fd);

    printf("fd : %d, fdb : %d\n", fd, fdb);
    
    struct stat stbuf1, stbuf2;
    fstat(fd, &stbuf1);
    fstat(fdb, &stbuf2);

    printf("fd inode_num : %d, fdb inode_num : %d\n", stbuf1.st_ino, stbuf2.st_ino);

    char buf[128] = {0x00};

    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "i am fdo\n");
    write(fd, buf, strlen(buf));

    memset(buf, 0x00, sizeof(buf));
    sprintf(buf, "i am fdb\n");
    write(fdb, buf, strlen(buf));

    off_t pos1, pos2;

    pos1 = lseek(fd, 0, SEEK_CUR);
    pos2 = lseek(fdb, 0, SEEK_CUR);

    printf("pos1 : %u, pos2 : %u\n", pos1, pos2);

    return 0;
}
