#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define FOOSPACE "          "

int
main(void)
{
    int fd = open("tmp.txt", O_CREAT|O_RDWR, S_IRWXU);
    if (fd < 0) exit(0);

    int i = 0;
    for (i = 0; i < 10; i++) {
        write(fd, FOOSPACE, sizeof(FOOSPACE));
    }
    //fsync(fd);
    
    void *pmmap = NULL;

    pmmap = mmap(NULL, 50, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if (pmmap == MAP_FAILED) perror("mmap err");

    sprintf(pmmap, "%s", "I am guiyao\n");

    while (1) pause();

    return 0;
}
