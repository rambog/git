#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char *argv[], char *envp[])
{
    time_t tn;
    struct tm tm;
    struct tm tmt;
    char timestr[1280];

    printf("sizeof time_t :%d sizeof int :%d\n", sizeof(time_t), sizeof(int));

    time(&tn);

    //ptm = gmtime(&tn);
    localtime_r(&tn, &tm);
    strftime(timestr, sizeof(timestr), "%F %H:%M:%S", &tm);
    printf("cur time : %s\n", timestr);

    sleep(2);
    strftime(timestr, sizeof(timestr), "%F %H:%M:%S", &tm);
    printf("cur time : %s\n", timestr);

    sleep(2);
    time(&tn);
    //gmtime(&tn);
    localtime_r(&tn, &tmt);
    strftime(timestr, sizeof(timestr), "%F %H:%M:%S", &tm);
    printf("cur time : %s\n", timestr);

#if 0
    for ( ; ; ) {
        tn += 100000000000000;
        ptm = gmtime(&tn);
        memset(timestr, 0x00, sizeof(timestr));

        strftime(timestr, sizeof(timestr), "%F %H:%M:%S", ptm);

        printf("cur time : %s\n", timestr);
        //sleep(1);
    }
#endif

    return 0;
}
