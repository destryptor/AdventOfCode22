#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void insertionSort(int*, int);

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

    int* visibility= (int*)malloc(numtrees*sizeof(int));




    rewind(fptr);

    int i=0, j;
    
    while(fgets(line, 10000, fptr)!=NULL){
        for(j=0; line[j]!='\n' && line[j]!='\0'; j++){
            treesMatrix[i][j]= line[j]-48;
        }
        i++;
    }

    int s=0;

    for(i=0; i<sqrt(numtrees); i++){
        
        for(j=0; j<sqrt(numtrees); j++){

            int flagup=0 , flagdown=0 , flagleft=0, flagright=0;

                for(int k=j-1; k>=0; k--){
                    if(treesMatrix[i][k]>=treesMatrix[i][j]){
                        flagleft++;
                        break;
                    }
                    flagleft++;
                }
                for(int k=j+1; k<sqrt(numtrees); k++){
                    if(treesMatrix[i][k]>=treesMatrix[i][j]){
                        flagright++;
                        break;
                    }
                    flagright++;
                }
                for(int k=i-1; k>=0; k--){
                    if(treesMatrix[k][j]>=treesMatrix[i][j]){
                        flagup++;
                        break;
                    }
                    flagup++;
                }
                for(int k=i+1; k<sqrt(numtrees); k++){
                    if(treesMatrix[k][j]>=treesMatrix[i][j]){
                        flagdown++;
                        break;
                    }
                    flagdown++;
                }

                visibility[s++]= flagleft* flagright* flagup* flagdown;             
        }
    }

    insertionSort(visibility, s);

    printf("%d\n", visibility[s-1]);
}

void insertionSort(int* arr, int size){
    // Insertion sort algorithm is used to arrange the array in ascending order.
    for (int i = 1 ; i <size;++i) {
        int key =arr[i];
        /* Move elements of arr[0..i-1], that are
        * greater than key, to one position ahead
        * of their current position */
       int j = i - 1;
       while ((j >= 0 && arr[j]>key))
       {
        arr[j + 1] = arr[j];
        --j;
        }
        arr[j + 1] = key;
        }
}