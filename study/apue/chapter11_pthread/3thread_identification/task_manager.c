#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>

#define PTHREADNUM  4

static void taskhandler(void *arg);

struct task {
    pthread_t t_tid;
    void *t_data;
    void (*t_handler)(void*);
    struct task *t_next;
};

struct tasklist {
    pthread_mutex_t t_mx; 
    pthread_cond_t t_cd;
    struct task *t_head; 
};

static void *
thr_func(void *arg)
{
    struct tasklist *plist = (struct tasklist*)arg;
    struct task *tmp, *prev;

    pthread_detach(pthread_self());

    for ( ; ; ) {
        pthread_mutex_lock(&plist->t_mx);

        while (plist->t_head == NULL)
            pthread_cond_wait(&plist->t_cd, &plist->t_mx);

        tmp = plist->t_head;
        prev = tmp;

        while (tmp != NULL) {
            if (pthread_equal(pthread_self(), tmp->t_tid)) {
                if (prev->t_next == tmp->t_next)
                    plist->t_head = NULL;
                else
                    prev->t_next = tmp->t_next;
                break;
            }
            prev = tmp;
            tmp = tmp->t_next;
        }

        pthread_mutex_unlock(&plist->t_mx);

        if (tmp != NULL) {
            tmp->t_handler(tmp->t_data);
            free(tmp);
        }
        tmp = NULL;
    }

    pthread_exit(0);
}

int
main(int argc, char *argv[])
{
    pthread_t tid[PTHREADNUM];
    int i = 0;
    int pthret;
    struct tasklist mtask;

    pthret = pthread_mutex_init(&mtask.t_mx, NULL);
    if (pthret != 0) {
        printf("pthreadmutex init err : %s\n", strerror(pthret));
        abort();
    }

    pthret = pthread_cond_init(&mtask.t_cd, NULL);
    if (pthret != 0) {
        printf("pthreadcond init err : %s\n", strerror(pthret));
        abort();
    }

    mtask.t_head = NULL;

    for (i = 0; i < PTHREADNUM; i++) {
        pthret = pthread_create(&tid[i], NULL, thr_func, (void*)&mtask); 
        if (pthret != 0) {
            printf("pthreadcreate err : %s\n", strerror(pthret));
            abort();
        }
    }

    struct task *factask;
    char tmpstr[128];
    struct task *tmp;
    unsigned char sigflag = 0;
    unsigned long long tick = 0;

    for ( ; ; ) {
        tmp = NULL;
        factask = (struct task*)malloc(sizeof(struct task));
        if (factask == NULL) {
            perror("malloc err");
            exit(0);
        }
        
        //srand(time(NULL));
        factask->t_tid = tid[(tick++)%4];
        factask->t_next = NULL;
        memset(tmpstr, 0x00, sizeof(tmpstr));
        sprintf(tmpstr, "%ld", (long)factask->t_tid);
        factask->t_data = (void*)strdup(tmpstr);
        factask->t_handler = taskhandler;

        pthread_mutex_lock(&mtask.t_mx);
        tmp = mtask.t_head;
        factask->t_next = mtask.t_head;
        mtask.t_head = factask;
        if (tmp == NULL)
            pthread_cond_broadcast(&mtask.t_cd);
        pthread_mutex_unlock(&mtask.t_mx);

        usleep(10*1000);
    }

    return 0;
}

static void 
taskhandler(void *arg)
{
    printf("I am thread(%ld) deal somedata : %s\n", (long)pthread_self(), (char*)arg);

    free(arg);
}
