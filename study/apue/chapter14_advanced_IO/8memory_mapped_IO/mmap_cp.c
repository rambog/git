#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <signal.h>
#include <unistd.h>
#include <errno.h>

#include <fcntl.h>
#include <sys/mman.h>

#define COPYINCR (1024*1024*1024)

int
main(int argc, char *argv[])
{
    int fdin, fdout;
    void *src, *dst;
    size_t copysz;
    struct stat sbuf;
    off_t fsz = 0;

    if (argc != 3) {
        printf("usage: %s <fromfile> <tofile>\n", argv[0]);
        exit(0);
    }

    fdin = open(argv[1], O_RDONLY);
    if (fdin < 0) exit(1);

    fdout = open(argv[2], O_RDWR|O_CREAT|O_TRUNC);
    if (fdout < 0) {
        perror("open err");
        exit(0);
    }

    if (fstat(fdin, &sbuf)) exit(0);

    if (ftruncate(fdout, sbuf.st_size) < 0) exit(0);

    while (fsz < sbuf.st_size) {
        if ((sbuf.st_size - fsz) > COPYINCR)
            copysz = COPYINCR;
        else
            copysz = sbuf.st_size - fsz;

        if ((src = mmap(NULL, copysz, PROT_READ, MAP_SHARED, fdin, fsz)) == MAP_FAILED) {
            perror("mmap err");
            return 0;
        }

        if ((dst = mmap(NULL, copysz, PROT_READ|PROT_WRITE, MAP_SHARED, fdout, fsz)) == MAP_FAILED) {
            perror("mmap err");
        }

        memcpy(dst, src, copysz);
        munmap(src, copysz);
        munmap(dst, copysz);
        fsz += copysz;
    }

    exit(0);
}
