#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Instructions to compile and run the program:
0.) Enter Vulcan
1.) gcc -o lab3 lab3.c
2.) ./lab3
3.) follow the prompts
4.) winner winner chicken dinner
*/

/* Function Declaration */
void sortArray(char word[], int size);
void displayArray(char word[], int size);

/* Main */
int main(void)
{
    char str[46];
    char *word;
    int size;
    printf("Please enter one word: \n");
    scanf("%s", &str);
    /* Dynamic memory allocation for array */
    word = (char *)malloc(strlen(str) + 1);
    strcpy(word, str);
    size = strlen(word);
    /* Function call/invocation */
    sortArray(word, size);
    displayArray(word, size);
    free(word);
    return 0;
}

/* Function definition */
void sortArray(char word[], int size)
{
    int currLoc, i;
    char temp;
    for (i = 1; i < size; i++)
    {
        currLoc = i;
        while (currLoc > 0 && word[currLoc - 1] > word[currLoc])
        {
            temp = word[currLoc - 1];
            word[currLoc - 1] = word[currLoc];
            word[currLoc] = temp;
            currLoc--;
        }
    }
}

void displayArray(char word[], int size)
{
    int i;
    printf("\nSorted array is: ");
    printf("[");
    for (i = 0; i < size; i++)
    {
        printf("%c, ", word[i]);
    }
    printf("%s]", word[size]);
}