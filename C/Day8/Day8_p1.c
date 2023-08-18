#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    FILE* fptr;

    fptr= fopen("C:/Users/Asus/Desktop/AdventOfCode22/Input/Day8.txt", "r");
    if(fptr==NULL){
        printf("\nFile not found\n");
        return 0;
    }

    char line[10000];
    int numtrees=0;

    while(fgets(line, 10000, fptr)!=NULL){
        for(int i=0; line[i]!='\n' && line[i]!= '\0'; i++, numtrees++);
    }

    int** treesMatrix= (int**)malloc(sqrt(numtrees)*sizeof(int*));

    for(int i=0; i<sqrt(numtrees); i++){
        treesMatrix[i]= (int*)malloc(sqrt(numtrees)*sizeof(int));
    }



    rewind(fptr);

    int i=0, j;
    
    while(fgets(line, 10000, fptr)!=NULL){
        for(j=0; line[j]!='\n' && line[j]!='\0'; j++){
            treesMatrix[i][j]= line[j]-48;
        }
        i++;
    }

    int count=0;

    for(i=0; i<sqrt(numtrees); i++){
        
        for(j=0; j<sqrt(numtrees); j++){

            int flagup=0 , flagdown=0 , flagleft=0, flagright=0;

            if(i==0 || j==0 || i==sqrt(numtrees)-1 || j==sqrt(numtrees)-1) count++;
            else{
                for(int k=0; k<j; k++){
                    if(treesMatrix[i][k]>=treesMatrix[i][j]) flagleft=1;
                }
                for(int k=j+1; k<sqrt(numtrees); k++){
                    if(treesMatrix[i][k]>=treesMatrix[i][j]) flagright=1;
                }
                for(int k=0; k<i; k++){
                    if(treesMatrix[k][j]>=treesMatrix[i][j]) flagup=1;
                }
                for(int k=i+1; k<sqrt(numtrees); k++){
                    if(treesMatrix[k][j]>=treesMatrix[i][j]) flagdown=1;
                }

                if(flagup==0 || flagdown==0 || flagleft==0 || flagright==0) count++;
            }
        }
    }

    printf("%d\n", count);

}