#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 100

typedef struct{
    char element[MAXLEN];
    int top;
} stack;

void init(stack *S){
    S->top=-1;
}

char top(stack *S){
    if (S->top==-1) return '\0';

    return S->element[S->top];
}

void push(stack *S, char ch){
    if(S->top==MAXLEN-1){
        printf("Full Stack!!!!!!!\n");
        return;
    }
    S->top++;
    S->element[S->top]=ch;
}

char pop(stack *S){
    if(S->top==-1){
        printf("Empty Stack!!!!!!\n");
        return '\0';
    }
    char ch= S->element[S->top];
    S->top--;
    return ch;
}

void print(stack *S){
    if(S->top==-1){
        printf("Empty Stack!!!!!!\n");
        return;
    }
    for(int i = S->top ;i>=0;--i ){
        printf("%c\n", S->element[i]);
    }
}


int main(){

    stack stacks[9];

    int i;

    for(i=0; i<9; i++){
        init(&stacks[i]);
    }

    push(&stacks[0], 'Q');
    push(&stacks[0], 'F');
    push(&stacks[0], 'M');
    push(&stacks[0], 'R');
    push(&stacks[0], 'L');
    push(&stacks[0], 'W');
    push(&stacks[0], 'C');
    push(&stacks[0], 'V');

    push(&stacks[1], 'D');
    push(&stacks[1], 'Q');
    push(&stacks[1], 'L');

    push(&stacks[2], 'P');
    push(&stacks[2], 'S');
    push(&stacks[2], 'R');
    push(&stacks[2], 'G');
    push(&stacks[2], 'W');
    push(&stacks[2], 'C');
    push(&stacks[2], 'N');
    push(&stacks[2], 'B');

    push(&stacks[3], 'L');
    push(&stacks[3], 'C');
    push(&stacks[3], 'D');
    push(&stacks[3], 'H');
    push(&stacks[3], 'B');
    push(&stacks[3], 'Q');
    push(&stacks[3], 'G');

    push(&stacks[4], 'V');
    push(&stacks[4], 'G');
    push(&stacks[4], 'L');
    push(&stacks[4], 'F');
    push(&stacks[4], 'Z');
    push(&stacks[4], 'S');

    push(&stacks[5], 'D');
    push(&stacks[5], 'G');
    push(&stacks[5], 'N');
    push(&stacks[5], 'P');

    push(&stacks[6], 'D');
    push(&stacks[6], 'Z');
    push(&stacks[6], 'P');
    push(&stacks[6], 'V');
    push(&stacks[6], 'F');
    push(&stacks[6], 'C');
    push(&stacks[6], 'W');

    push(&stacks[7], 'C');    
    push(&stacks[7], 'P');    
    push(&stacks[7], 'D');    
    push(&stacks[7], 'M');    
    push(&stacks[7], 'S');

    push(&stacks[8], 'Z');    
    push(&stacks[8], 'N');    
    push(&stacks[8], 'W');    
    push(&stacks[8], 'T');    
    push(&stacks[8], 'V');    
    push(&stacks[8], 'M');    
    push(&stacks[8], 'P');    
    push(&stacks[8], 'C');    


    
    FILE* fptr;
    fptr= fopen("C:/Users/Asus/Desktop/AdventOfCode22/Input/Day5.txt", "r");

    if(fptr==NULL){
        printf("\nError opening file\n");
        exit(-1);
    }

    char buffer[1000];
    char crates[1000];

    int numpops, from, to;

    while(fgets(buffer, 1000, fptr)!= NULL){
        if(sscanf(buffer, "move %d from %d to %d", &numpops, &from, &to)){   
            for(i=0; i<numpops; i++){
                crates[i]= pop(&stacks[from-1]);
            }
            for(i=numpops-1; i>=0; i--){
                push(&stacks[to-1], crates[i]);
            }
        }
        
    }

    char topch[9];
    for(i=0; i<9; i++){
        topch[i]=top(&stacks[i]);
    }

    for(i=0; i<9; i++){
        printf("%c", topch[i]);
    }

    return 0;

}