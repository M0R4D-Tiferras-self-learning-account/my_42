#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>


void handler(int signumber) {
    printf("Received signal %d\n", signumber);
    exit(0);
}

int main() {
    signal(SIGINT, handler);
    printf("\nThe PID = %d\n", getpid());
    while(1)
    {

    }
    return 0;
}

