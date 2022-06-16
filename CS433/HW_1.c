#include <stdio.h>

int main(int argc, char *argv[])
{
    int counter;
    printf("Program name is: %s \n", argv[0]);
    if (argc == 1)
    {
        printf("There are no extra Command Line Arguments. \n");
    }
    if (argc >= 2)
    {
        printf("Number of arguments passed: %d. \n", argc);
        printf("These are the arguments put in. \n");
        for (counter = 0; counter < argc; counter++)
        {
            printf("argv[%d]: %s \n", counter, argv[counter]);
        }
    }
    return 0;
}