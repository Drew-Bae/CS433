#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    char *arr[] = {"ls", "-la", NULL};
    execv("/bin/ls", arr);
    return (0);
}