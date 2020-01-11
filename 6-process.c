#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    pid_t fpid, xid;
    int status, i;
    fpid = fork();
    if (fpid < 0) {
        printf("error creat");
    } else if (0 == fpid) {
        for (int i = 0; i < 3; i++) {
            if (3 == i)
                exit(0);
            printf("I am coming!%d\n", getpid());
            sleep(2);
        }
    } else {
        for (int i = 0; i < 3; i++) {
            sleep(1);
            printf("I am brook!%d\n", getppid());
        }
        xid = wait(&status);
        i = WEXITSTATUS(status);
        printf("child's pid = %d. exit status = %d\n", xid, i);

        return  0;
    }
}