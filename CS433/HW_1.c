#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Contains find_Str */
void find_str(char const *str, char const *substr)
{
    char *pos = strstr(str, substr);
    if (pos)
    {
        printf("found the string '%s' in '%s' at position: %ld\n", substr, str, pos - str);
    }
    else
    {
        printf("the string '%s' was not found in '%s'\n", substr, str);
    }
}

/* Contains getting the arguments and getline */
int main(int argc, char *argv[])
{
    /* These are for the command line */
    int keyword;
    int counter;
    /* These are for the getline */
    char *line = NULL;
    size_t maxlen = 0;
    ssize_t n;

    if (argc == 1)
    {
        printf("There are no extra Command Line Arguments. \n");
    }
    if (argc >= 2)
    {
        /* second part */
        while ((n = getline(&line, &maxlen, stdin)) > 0)
        {
            printf("Line read:\n[%s]", line);
        }
        free(line);

        /* first part */
        printf("Number of arguments passed: %d. \n", argc);
        printf("Here is the number of times each keyword appears: \n");
        for (keyword = 1; keyword < argc; keyword++)
        {
            /* if keyword then this function here */
            printf("%s: %d \n", argv[keyword], counter);
        }
    }
    return 0;
}