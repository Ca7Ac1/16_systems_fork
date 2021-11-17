#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

int main()
{
    printf("Parent starting!\n");

    int f = fork();

    if (f)
    {      
        f = fork();
    }


    if (f)
    {
        int status;
        wait(&status);

        printf("Child asleep for %d seconds\n", WEXITSTATUS(status));
        printf("Parent finished!\n");
    }
    else
    {
        srand(getpid());

        int seconds = rand() % 4 + 2;
        printf("Child's PID: %d\n", getpid());

        sleep(seconds);
        printf("Child %d Finished\n", getpid());
        // printf("PID: %d Seconds:%d\n", getpid(), seconds);

        return seconds;
    }

    return 0;
}
