#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

int
main(void)
{
    int fd = open("tmp.txt", O_CREAT|O_RDWR, S_IRWXU);
    if (fd < 0) exit(0);

    void *mapfd = NULL;

    mapfd = mmap(NULL, 16, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
    if (mapfd == MAP_FAILED) perror("mmap err");

    ((char*)mapfd)[0] = 'I';
    return 0;
}
