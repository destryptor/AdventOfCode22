#include <stdio.h>

int main()
{
    FILE *fptr;
    fptr = fopen("C:/Users/Asus/Desktop/AdventOfCode22/Input/Day2.txt", "r");

    char buffer[10000];

    int score = 0;

    char choice1, choice2;

    while (fgets(buffer, 10000, fptr) != NULL)
    {
        sscanf(buffer, "%c %c", &choice1, &choice2);

        if (choice2 == 'X')
        {
            score += 1;
            if (choice1 == 'C')
            {
                score += 6;
            }
            else if (choice1 == 'A')
            {
                score += 3;
            }
        }
        if (choice2 == 'Y')
        {
            score += 2;
            if (choice1 == 'A')
            {
                score += 6;
            }
            else if (choice1 == 'B')
            {
                score += 3;
            }
        }
        if (choice2 == 'Z')
        {
            score += 3;
            if (choice1 == 'B')
            {
                score += 6;
            }
            else if (choice1 == 'C')
            {
                score += 3;
            }
        }
    }

    printf("Score: %d", score);

    return 0;
}