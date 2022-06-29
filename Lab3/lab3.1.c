#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Instructions to compile and run the program:
0.) Enter Vulcan
1.) gcc -o lab3.1 lab3.1.c
2.) ./lab3.1
3.) follow the prompts
4.) winner winner chicken dinner
*/

/* Function Declaration */
void sortArray(char *word[], int size);
void displayArray(char *word[], int size);

/* Main */
int main(void)
{
    char str[5][46];
    char **word;
    int size, i;
    printf("Please enter 5 words: \n");
    for (i = 0; i < 5; i++)
    {
        scanf("%46s", str[i]);
    }
    /* Dynamic memory allocation for array */
    word = malloc(5 * sizeof(char *));
    for (i = 0; i < 5; i++)
    {
        word[i] = malloc(5 * sizeof(char));
    }
    for (i = 0; i < 5; i++)
    {
        strcpy(word[i], str[i]);
    }
    size = 5;
    /* Function call/invocation */
    sortArray(word, size);
    displayArray(word, size);
    free(word);
    return 0;
}

/* Function definition */
void sortArray(char *word[], int size)
{
    int currLoc, i;
    char *temp;
    for (i = 1; i < size; i++)
    {
        currLoc = i;
        while (currLoc > 0 && strcmp(word[currLoc], word[currLoc - 1]) < 0)
        {
            temp = word[currLoc - 1];
            word[currLoc - 1] = word[currLoc];
            word[currLoc] = temp;
            currLoc--;
        }
    }
}

void displayArray(char *word[], int size)
{
    int i;
    printf("\nSorted array is: ");
    printf("[");
    for (i = 0; i < size; i++)
    {
        printf("%s, ", word[i]);
    }
    printf("%s]", word[size]);
}