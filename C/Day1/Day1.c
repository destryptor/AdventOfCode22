#include<stdio.h>
#include<stdlib.h>

void insertionSort(int[], int);

int main(){
    printf("Enter the file name to be read: ");
    char fileName[10];
    scanf("%s", fileName);

    FILE *fptr;

    fptr= fopen(fileName, "r");

    char buffer[10000];
    int numElves=0;

    while(fgets(buffer, 10000, fptr)!= NULL){
        if(buffer[0]=='\n'){
            numElves++;
        }
    }

    numElves++;

    printf("%d", numElves);

    int* sumArray= (int*)malloc(numElves*sizeof(int));

    int sum;
    int calorie;

    rewind(fptr);

    int i;

    for(i=0; i<numElves; i++){
        sum=0;
        while(fgets(buffer, 10000, fptr)!=NULL){
            if(buffer[0]=='\n'){
                break;
            }
            if(sscanf(buffer, "%d", &calorie)){
                sum+=calorie;
            }
        }
        sumArray[i]=sum;
    }

    insertionSort(sumArray, numElves);

    printf("Max calories: %d", sumArray[numElves-1]+sumArray[numElves-2]+sumArray[numElves-3]);   //sum of top 3 caloriesums

    


}

void insertionSort(int arr[], int length){
    int i, j, key;

    for(j=1; j<length; j++){
        key= arr[j];
        i = j - 1;
        // Move elements of arr[] that are greater than key, to one position ahead
        // of their current position
        while (arr[i]>key && i>=0) {
            arr[i + 1] = arr[i];
            --i;
        }
        arr[i+1] = key;
    }
}