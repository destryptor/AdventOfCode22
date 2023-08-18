#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fptr;

    fptr = fopen("C:/Users/Asus/Desktop/AdventOfCode22/Input/Day10.txt", "r");
    if (fptr == NULL)
    {
        printf("Error in opening file\n");
        return -1;
    }

    int X = 1;
    int cycles = 0;
    int addx;

    char buffer[10000];
    int signalstrength[6];
    int k = 0;

    while (fgets(buffer, 10000, fptr) != NULL)
    {

        if ((strcmp(buffer, "noop\n") == 0) || (strcmp(buffer, "noop") == 0))
        {
            
            if (cycles == 20 || cycles == 60 || cycles == 100 ||
                cycles == 140 || cycles == 180 || cycles == 220)
            {
                printf("%d\n", X);
                signalstrength[k++] = cycles * X;
            }
            cycles++;
        }
        else
        {

            
            if (cycles == 20 || cycles == 60 || cycles == 100 ||
                cycles == 140 || cycles == 180 || cycles == 220)
            {
                printf("%d\n", X);
                signalstrength[k++] = cycles * X;
            }
            cycles++;

            

            if (cycles == 20 || cycles == 60 || cycles == 100 ||
                cycles == 140 || cycles == 180 || cycles == 220)
            {
                printf("%d\n", X);
                signalstrength[k++] = cycles * X;
            }
            sscanf(buffer, "addx %d\n", &addx);
            X += addx;
            cycles++;
        }
    }

    int sumstrength = 0;

    for (int i = 0; i < 6; i++)
    {
        sumstrength += signalstrength[i];
    }

    printf("%d\n", sumstrength);
}
