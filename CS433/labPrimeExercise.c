#include <stdio.h>

int main()
{
    int given_number;
    int i = 5;

    printf("Enter your number: \n");
    scanf("%d", given_number);

    if (given_number == 2 || given_number == 3)
    {
        printf("%d is prime. \n", given_number);
    }

    else if (given_number <= 1 || given_number % 2 == 0 || given_number % 3 == 0)
    {
        printf("%d is not prime. \n", given_number);
    }

    for (i *i <= given_number; i += 6;)
    {
        if (given_number % i == 0 || given_number % (i + 2) == 0)
        {
            printf("%d is not prime. \n", given_number);
        }
    }

    printf("%d is a prime. \n", given_number);
}