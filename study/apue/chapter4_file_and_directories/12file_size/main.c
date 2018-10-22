#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("usage : %s <file>\n", argv[0]);
        return 1;
    }

    printf("point type bytes : %u, off_t type bytes : %u\n", sizeof(void*), sizeof(off_t));

    struct stat statbuf;

    if (stat(argv[1], &statbuf) != 0) {
        printf("stat err : %m\n");
        return 1;
    }
    
    printf("best I/O block size : %u, number of disk blocks : %u, file length : %d\n", 
                statbuf.st_blksize, statbuf.st_blocks, statbuf.st_size);

    int fd = -1;
    fd = open(argv[1], O_RDWR);
    if (fd < 0) {
        printf("open err : %m\n");
        return 1;
    }

    ssize_t nread, nwrite;
    char *tmp = "I am rambo\n";

    nwrite = write(fd, tmp, strlen(tmp));
    if (nwrite != strlen(tmp)) {
        printf("write err : %m\n");
        return 1;
    }

    off_t curpos;
    curpos = lseek(fd, 0, SEEK_CUR);
    if (curpos == -1) {
        printf("lseek err : %m\n");
        return 1;
    } else 
        printf("file %s seek curpos : %d\n", argv[1], curpos);

    curpos = lseek(fd, statbuf.st_blksize*10, SEEK_SET);
    if (curpos == -1) {
        printf("lseek err : %m\n");
        return 1;
    } else
        printf("file %s seek hole curpos : %d\n", argv[1], curpos);
    
    tmp = "I am rambo again\n";
    nwrite = write(fd, tmp, strlen(tmp));
    if (nwrite != strlen(tmp)) {
        printf("write err : %m\n");
        return 1;
    }

    if (fstat(fd, &statbuf) < 0) {
        printf("stat err : %m\n");
        return 1;
    }

    printf("best I/O block size : %u, number of disk blocks : %u, file length : %d\n", 
                statbuf.st_blksize, statbuf.st_blocks, statbuf.st_size);

    close(fd);
    
    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        printf("open err : %m\n");
        return 1;
    }

    void *buf = (void*)malloc(statbuf.st_blksize);
    if (buf == NULL) {
        printf("malloc err : %m\n");
        return 1;
    }

    int readcnt = 0;
    while ((nread = read(fd, buf, statbuf.st_blksize)) > 0) {
        readcnt++;
        printf("readcnt : %u, readsize : %d", readcnt, nread);
        
        int i = 0;
        unsigned char *rtmp = (unsigned char *)buf;
        for (i = 0; i < statbuf.st_blksize; i++) {
            if (rtmp[i] != 0x00) {
                printf(" cur read not all zero\n");
                break;
            } else if (i == statbuf.st_blksize - 1) {
                printf(" cur read is all zero\n");
            }
        } 
    }

    exit(0);
}
