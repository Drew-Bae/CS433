#include <stdio.h>
#include <stdlib.h>

/*
Instruction:
#0.) Vulcan execution
#1.) gcc -o insert insertionSort.c
#2.) ./insert
#3.) Read the printf statements and follow
 */

int main(int argc, char **argv)
{
    int input, i, inputTwo;
    printf("Please enter number of elements in array: ");
    scanf("%d", &input);
    int arr[input + 1];
    for (i = 0; i < input; i++)
    {
        printf("Please enter element %d of array: ", i);
        scanf("%d", &inputTwo);
        arr[i] = inputTwo;
    }

    /* Display */
    printf("Given array is: ");
    printf("[");
    for (i = 0; i < input - 1; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("%d]", arr[input - 1]);

    /* Naive InsertionSort */
    int temp, currLoc;
    for (i = 1; i < input; i++)
    {
        currLoc = i;
        while (currLoc > 0 && arr[currLoc - 1] > arr[currLoc])
        {
            temp = arr[currLoc];
            arr[currLoc] = arr[currLoc - 1];
            arr[currLoc - 1] = temp;
            currLoc--;
        }
    }

    /* Display */
    printf("\nSorted array is: ");
    printf("[");
    for (i = 0; i < input - 1; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("%d]", arr[input - 1]);
}