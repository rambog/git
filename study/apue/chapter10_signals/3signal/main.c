#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>

#define PRINTSIG(SIGNO) printf("get signal : %s\n", #SIGNO)

static void
trigger_sig(char *sigstr);

static void
sigfunc(int signo)
{
    switch (signo) {
        case SIGSTOP :
            PRINTSIG(SIGSTOP);
            break;
        case SIGKILL : 
            PRINTSIG(SIGKILL);
            break;
        case SIGINT :
            PRINTSIG(SIGINT);
            exit(0);
            break;
        case SIGQUIT :
            PRINTSIG(SIGQUIT);
            break;
        case SIGTSTP :
            PRINTSIG(SIGTSTP);
            break;
        case SIGABRT :
            PRINTSIG(SIGABRT);
            break;
        case SIGALRM :
            PRINTSIG(SIGALRM);
            break;
        case SIGSEGV :
            PRINTSIG(SIGSEGV);
            break;
        case SIGCHLD :
            PRINTSIG(SIGCHLD);
            break;
        case SIGFPE :
            PRINTSIG(SIGFPE);
            break;
        case SIGTERM:
            PRINTSIG(SIGTERM);
            break;
        case SIGUSR1:
            PRINTSIG(SIGUSR1);
            break;
        default :
            return;
    }
}

static void
sigfunc_new(int signo)
{
    switch (signo) {
        case SIGSTOP :
            PRINTSIG(SIGSTOP);
            break;
        case SIGKILL : 
            PRINTSIG(SIGKILL);
            break;
        case SIGINT :
            PRINTSIG(SIGINT);
            break;
        case SIGQUIT :
            PRINTSIG(SIGQUIT);
            break;
        case SIGTSTP :
            PRINTSIG(SIGTSTP);
            break;
        case SIGABRT :
            PRINTSIG(SIGABRT);
            break;
        case SIGALRM :
            PRINTSIG(SIGALRM);
            break;
        case SIGSEGV :
            PRINTSIG(SIGSEGV);
            break;
        case SIGCHLD :
            PRINTSIG(SIGCHLD);
            break;
        case SIGFPE :
            PRINTSIG(SIGFPE);
            break;
        default :
            return;
    }
}

int
main(int argc, char *argv[], char *envp[])
{
    void (*sigret)(int);

#if 0
    sigret = signal(SIGSTOP, sigfunc);
    if (sigret == SIG_ERR) {
        perror("reg SIGSTOP fail");
    }
    sigret = signal(SIGKILL, sigfunc);
    if (sigret == SIG_ERR) {
        perror("reg SIGKILL fail");
    }

    sigret = signal(SIGSTOP, SIG_IGN);
    if (sigret == SIG_ERR) {
        perror("reg SIGSTOP fail");
    }
    sigret = signal(SIGKILL, SIG_IGN);
    if (sigret == SIG_ERR) {
        perror("reg SIGKILL fail");
    }
#endif

    sigret = signal(SIGINT, sigfunc); 
    if (sigret == SIG_ERR) 
        perror("reg SIGIN fail");
    else 
        printf("before sighandler addr : %p\n", sigret);

    sigret = signal(SIGQUIT, sigfunc);
    if (sigret == SIG_ERR) 
        perror("reg SIGQUIT fail");
    else 
        printf("before sighandler addr : %p\n", sigret);

    sigret = signal(SIGTSTP, sigfunc);
    if (sigret == SIG_ERR) 
        perror("reg SIGTSTP fail");
    else 
        printf("before sighandler addr : %p\n", sigret);

    sigret = signal(SIGABRT, sigfunc);
    if (sigret == SIG_ERR)
        perror("reg SIGABRT fail");
    else 
        printf("before sighandler addr : %p\n", sigret);

    sigret = signal(SIGALRM, sigfunc);
    if (sigret == SIG_ERR)
        perror("reg SIGALRM fail");
    else 
        printf("before sighandler addr : %p\n", sigret);

    sigret = signal(SIGSEGV, sigfunc);
    if (sigret == SIG_ERR)
        perror("reg SIGSEGV fail");
    else 
        printf("before sighandler addr : %p\n", sigret);

    sigret = signal(SIGCHLD, sigfunc);
    if (sigret == SIG_ERR)
        perror("reg SIGCHLD fail");
    else 
        printf("before sighandler addr : %p\n", sigret);

    sigret = signal(SIGFPE, sigfunc);
    if (sigret == SIG_ERR)
        perror("reg SIGFPE fail");
    else 
        printf("before sighandler addr : %p\n", sigret);

    sigret = signal(SIGTERM, sigfunc);
    if (sigret == SIG_ERR)
        perror("reg SIGTERM fail");
    else 
        printf("before sighandler addr : %p\n", sigret);

    sigret = signal(SIGUSR1, sigfunc);
    if (sigret == SIG_ERR)
        perror("reg SIGUSR1 fail");
    else 
        printf("before sighandler addr : %p\n", sigret);

    //sigret = signal(SIGUSR1, sigfunc_new);
    //if (sigret == SIG_ERR)
        //perror("reg SIGUSR1 fail");
    //else if (sigret == sigfunc)
        //printf("sig SIGUSR1 before sighandler is sigfunc\n");

    trigger_sig(argv[1]);
    //for ( ; ; )
        pause();

    return 0;
}

static void
trigger_sig(char *sigstr)
{
    if (sigstr == NULL)
        return;

    if (strcmp(sigstr, "SIGABRT") == 0) {
        abort();
        return;
    }

    if (strcmp(sigstr, "SIGALRM") == 0) {
        return;
    }

    if (strcmp(sigstr, "SIGSEGV") == 0) {
        *((char*) 0) = 0x00;
        return;
    }

    if (strcmp(sigstr, "SIGCHLD") == 0) {
        pid_t pid;
        pid = fork();
        if (fork < 0) {
            exit(0);
        } else if (pid == 0) {
            execl("child", "child", NULL);
            perror("execl err : %m\n");
        }

        return;
    }

    if (strcmp(sigstr, "SIGFPE") == 0) {
        double tmp = 9.0/0;
        return;
    }
}

