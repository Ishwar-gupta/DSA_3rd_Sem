#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int);
void pop();
void display();
void peek(){
    printf("Top Element is %d\n",stack[top]);
}

int main(){
    display();
    push(10);
    push(20);
    push(30);
    pop();
    peek();
    display();

    return 0;
}
void push(int item){

    // check for overflow
    if(top==MAX-1){
        printf("Stack Overflow.\n");
        return ;
    }
    stack[++top]=item;
    printf("%d pushed into stack\n",item);
}

void pop(){

    // check for underflow
    if(top==-1){
        printf("Stack Underflow.\n");
    }
    int item = stack[top--];
    printf("%d is popped from stack.\n",item);
}

void display(){
    // check for underflow
    if(top==-1){
        printf("Stack Underflow.\n");
    }
    printf("Current Stack:");
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
    printf("\n");
 }