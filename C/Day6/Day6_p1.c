#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE* fptr;
    fptr= fopen("C:/Users/Asus/Desktop/AdventOfCode22/Input/Day6.txt", "r");
    if(fptr==NULL){
        printf("\nFile not found\n");
        return 0;
    }

    int datalen=0;
    char temp;

    while(getc(fptr)!=EOF){
        datalen++;
    }

    char* buffer= (char*)malloc((datalen+1)*sizeof(char));

    rewind(fptr);

    fgets(buffer, datalen+1 , fptr);
    fclose(fptr);

    printf("%s\n", buffer);

    int i, j;
    int flag;

    int markerPosition=-1;

   for (i = 0; i < datalen - 3; i++) {
        if (buffer[i] != buffer[i + 1] &&
            buffer[i] != buffer[i + 2] &&
            buffer[i] != buffer[i + 3] &&
            buffer[i + 1] != buffer[i + 2] &&
            buffer[i + 1] != buffer[i + 3] &&
            buffer[i + 2] != buffer[i + 3]) {
            markerPosition = i;
            break;
        }
    }


    printf("%d", markerPosition+4);

    return 0;

}