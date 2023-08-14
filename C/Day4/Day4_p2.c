#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int start;
    int end;
} time;

int main(){
    FILE* fptr;

    fptr= fopen("C:/Users/Asus/Desktop/AdventOfCode22/Input/Day4.txt", "r");
    if(fptr==NULL){
        printf("\nError opening file\n");
        exit(-1);
    }

    char buffer[10000];

    time time1, time2;

    int containtime=0;

    while(fgets(buffer, 10000, fptr)!= NULL){
        sscanf(buffer, "%d-%d,%d-%d", &time1.start, &time1.end, &time2.start, &time2.end);

        if(((time2.start>=time1.start)&&(time2.start<=time1.end)) || ((time1.start>=time2.start)&&(time1.start<=time2.end))){
            containtime++;
        }
    }

    printf("Completely contained intervals= %d", containtime);

    return 0;
}