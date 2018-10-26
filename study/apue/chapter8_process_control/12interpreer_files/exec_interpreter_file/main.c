#include "apue.h"
#include <sys/wait.h>

int
main(void)
{
    pid_t pid;

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        if (execl("/root/git/study/apue/chapter8_process_control/13interpreter_files/exec_interpreter_file/echoall/testinterp",
                    "rambo", "myargl", "MY ARG2", NULL) < 0)
            err_sys("execl error");
    }

    if (waitpid(pid, NULL, 0) < 0)
        err_sys("waitpid errorr");

    exit(0);
}
