#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Contains find_Str */
int find_str(char const *str, char const *substr)
{
    char *pos = strstr(str, substr);
    if (pos)
    {
        return 1;
    }
    else
    {
        return 0;
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
        for (keyword = 1; keyword < argc; keyword++)
        {
            while ((n = getline(&line, &maxlen, stdin)) > 0)
            {
                char *token = strtok(line, " ");
                while (token)
                {
                    if (find_str(token, argv[keyword]) == 1)
                    {
                        counter++;
                    }
                    token = strtok(NULL, " ");
                }
            }
            printf("%s: %d \n", argv[keyword], counter);
            counter = 0;
            free(line);
            line = NULL;
            n = 0;
            maxlen = 0;
        }
    }
    return 0;
}