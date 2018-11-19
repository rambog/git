#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>

int
main()
{
    int fd = open("tmp.txt", O_RDWR);
    if (fd < 0) exit(0);

    char foo[128];

    printf("first readn:%d str:%s\n", read(fd, foo, sizeof(foo)), foo);
    memset(foo, 0x00, sizeof(foo));
    printf("first str:%s readn:%d\n", foo, read(fd, foo, sizeof(foo)));
    
    return 0;
}
