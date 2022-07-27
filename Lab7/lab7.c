/*
To Compile: gcc -o lab7 hw7.c
To run: ./lab7 ~/CS433/Lab7/hw1 <size>
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

int main(int argc, char **argv)
{
    pid_t pid;
    int status;
    time_t starttime, endtime;

    if (argc < 2)
    {
        printf("Usage: %s [arg]\n", argv[0]);
        exit(-1);
    }
    pid = fork();
    if (pid == 0)
    { /* This is the child process */
        execvp(argv[1], &argv[1]);
        printf("If you see this statement then execvp failed \n");
        perror("execvp");
        exit(-1);
    }
    else if (pid > 0)
    { /* This is the parent process */
        time(&starttime);
        wait(&status);
        printf("%s", ctime(&starttime));
        if (WIFEXITED(status))
        { /* Child process terminated normally */
            time(&starttime);
        }
        else
        { /* Child process did not terminate normally */
            printf("Child process did not terminate normally!\n");
        }
    }
    else
    { /* Error */
        perror("fork");
        exit(EXIT_FAILURE);
    }

    printf("%s", ctime(&starttime));

    return 0;
}