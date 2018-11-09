#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>

struct threadret {
    int t_num1;
    int t_num2;
    int t_num3;
    int t_num4;
};

static void *
thr_fn(void *arg)
{
    static struct threadret thret;
    memset(&thret, 0x00, sizeof(struct threadret));

    thret.t_num1 = 1;
    thret.t_num2 = 2;
    thret.t_num3 = 3;
    thret.t_num4 = 4;

    pthread_exit((void*)&thret);
}

int 
main(void)
{
    pthread_t tid;
    int err;

    err = pthread_create(&tid, NULL, thr_fn, NULL);
    if (err != 0) {
        printf("pthrad_create err : %s\n", strerror(err));
        exit(0);
    }

    struct threadret *tret;

    err = pthread_join(tid, (void**)&tret);
    if (err != 0) {
        printf("pthread_join err : %s\n", strerror(err));
        exit(0);
    }

    printf("t_num1 : %d\n", tret->t_num1);
    printf("t_num2 : %d\n", tret->t_num2);
    printf("t_num3 : %d\n", tret->t_num3);
    printf("t_num4 : %d\n", tret->t_num4);

    return 0;
}
