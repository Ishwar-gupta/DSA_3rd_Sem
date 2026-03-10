#include<stdio.h>
#define MAX_SIZE 3

struct stack
{
   int tos;
   int item[MAX_SIZE];
};

typedef struct stack st;


void createEmpty(st *s){
    s->tos=-1;
}

void push(st *s , int x){
    if(isFull(s)){
        printf("stack is overflow.");
    }else{
        s->tos++;
        s->item[s->tos]=x;
    }
}

int isFull(st *s){
    if(s->tos==MAX_SIZE-1){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(st *s){
    if(s->tos==-1){
        return 1;
    }else{
        return 0;
    }
}
void pop(st *s){
    int x;
    if(isEmpty(s)){
        printf("stack is empty");
    }else{
        x=s->item[s->tos];
        s->tos--;
        printf("Popped element is: %d",x);
        // printf("Popped element is: %d",x);

    }
}


int main(){

    st s1;
    createEmpty(&s1);
    push(&s1,100);
    push(&s1,80);
    push(&s1,70);
    push(&s1,120);
    pop(&s1);
    return 0;
}