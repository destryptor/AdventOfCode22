// program to read input of strings of variable length from a file, split them in half and then find the common element in them, to rank them accordingly

#include <stdio.h>
#include <stdlib.h>

int rank(char);
char commonchar(char[], char[], char[], int, int, int);

int main()
{
    FILE *fptr;

    fptr = fopen("C:/Users/Asus/Desktop/AdventOfCode22/Input/Day3.txt", "r");
    if (fptr == NULL)
    {
        printf("Error in reading file");
        return 0;
    }

    char buffer1[10000];
    char buffer2[10000];
    char buffer3[10000];
    char commonc;
    int indrank = 0;
    int totalrank = 0;

    while (fgets(buffer1, 10000, fptr) != NULL)
    {
        fgets(buffer2, 10000, fptr);
        fgets(buffer3, 10000, fptr);
        int i, j, k;

        for (i = 0; (buffer1[i] != '\n') && (buffer1[i] != '\0'); i++)
            ;
        for (j = 0; (buffer2[j] != '\n') && (buffer2[j] != '\0'); j++)
            ;
        for (k = 0; (buffer3[k] != '\n') && (buffer3[k] != '\0'); k++)
            ;

        commonc = commonchar(buffer1, buffer2, buffer3, i, j, k);
        indrank = rank(commonc);

        totalrank += indrank;
    }

    printf("Total ranks: %d", totalrank);

    return 0;
}

char commonchar(char buf1[], char buf2[], char buf3[], int size1, int size2, int size3)
{
    char commonc;
    int i, j, k;

    for (i = 0; i < size1; i++)
    {
        for (j = 0; j < size2; j++)
        {
            for (k = 0; k < size3; k++)
            {
                if (buf1[i] == buf2[j] && buf1[i] == buf3[k])
                {
                    commonc = buf1[i];
                }
            }
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