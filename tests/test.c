#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char **argv)
{
    int pid = atoi(argv[1]);


    kill(pid, SIGINT);
    printf("SIGINT sent to %d\n", pid);
    return 0;
}