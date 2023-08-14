// program to read input of strings of variable length from a file, split them in half and then find the common element in them, to rank them accordingly

#include <stdio.h>
#include <stdlib.h>

int rank(char);
char commonchar(char[], char[], int, int);

int main()
{
    FILE *fptr;

    fptr = fopen("C:/Users/Asus/Desktop/AdventOfCode22/Input/Day3.txt", "r");
    if (fptr == NULL)
    {
        printf("Error in reading file");
        return 0;
    }

    char buffer[10000];
    char commonc;
    int indrank = 0;
    int totalrank = 0;

    while (fgets(buffer, 10000, fptr) != NULL)
    {
        int i;

        for (i = 0; (buffer[i] != '\n') && (buffer[i] != '\0'); i++)
            ;

        char *leftHalf = (char *)malloc(i / 2 * sizeof(char));
        char *rightHalf = (char *)malloc(i / 2 * sizeof(char));

        int j, k, l;

        for (j = 0; j <= i / 2; j++)
        {
            leftHalf[j] = buffer[j];
        }

        for (l = 0; l < i / 2; l++)
        {
            printf("%c", leftHalf[l]);
        }
        printf("\n");

        for (j = 0, k = i / 2; k < i; j++, k++)
        {
            rightHalf[j] = buffer[k];
        }
        for (l = 0; l < i / 2; l++)
        {
            printf("%c", rightHalf[l]);
        }
        printf("\n\n");

        commonc = commonchar(leftHalf, rightHalf, i / 2, i / 2);
        indrank = rank(commonc);

        totalrank += indrank;
    }

    printf("Total ranks: %d", totalrank);

    return 0;
}

char commonchar(char leftHalf[], char rightHalf[], int leftsize, int rightsize)
{
    char commonc;
    int i, j;

    for (i = 0; i < leftsize; i++)
    {
        for (j = 0; j < rightsize; j++)
        {
            if (leftHalf[i] == rightHalf[j])
                commonc = leftHalf[i];
        }
    }
    return commonc;
}

int rank(char c)
{
    int indrank;

    if ((int)c >= 97 && (int)c <= 122)
    {
        indrank = (int)c - 96;
    }
    else
    {
        indrank = (int)c - 38;
    }
    return indrank;
}