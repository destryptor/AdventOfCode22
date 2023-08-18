#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char line[32];
    int drawing[6][40];
    int cycle = 1;
    int x_register = 1;
    FILE *fptr;
    if ((fptr = fopen("C:/Users/Asus/Desktop/AdventOfCode22/Input/Day10.txt", "r")) == NULL)
    {
        printf("ERROR: Could not open file");
        exit(1);
    }
    while (fgets(line, 32, fptr))
    {
        char *operation = strtok(line, " ");
        int x_change = atoi(strtok(NULL, " "));
        if (strcmp(operation, "addx") == 0)
        {
            int pixel_y = (cycle - 1) / 40;
            int pixel_x = (cycle - 1) % 40;
            drawing[pixel_y][pixel_x] = x_register - 1 <= pixel_x && pixel_x <= x_register + 1;
            cycle++;

            pixel_y = (cycle - 1) / 40;
            pixel_x = (cycle - 1) % 40;
            drawing[pixel_y][pixel_x] = x_register - 1 <= pixel_x && pixel_x <= x_register + 1;
            ;
            cycle++;

            x_register += x_change;
        }
        else
        {
            int pixel_y = (cycle - 1) / 40;
            int pixel_x = (cycle - 1) % 40;
            drawing[pixel_y][pixel_x] = x_register - 1 <= pixel_x && pixel_x <= x_register + 1;
            cycle++;
        }
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            printf(drawing[i][j] ? "0" : " ");
        }
        printf("\n");
    }
}
