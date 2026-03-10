#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
int stack[MAX_SIZE];
int top=-1;
//funx prototype
void push(int item);
void pop();
void display();

//main funx
int main(){
int item,choice;
printf("\n 1.Push\n 2.Pop \n 3.Display \n  4. Exit\n");

while(1){
    printf("Enter your choice:");

    if(scanf("%d",&choice)!=1){
        printf("Invalid input, please enter a number from menu.\n");
        while(getchar()!='\n' && !feof(stdin));
        continue;
    }

    switch (choice)
    {
    case 1:
        printf("Enter item to be inserted:");
        if(scanf("%d",&item)!=1){
            printf("Invalid input, please enter a valid integer item.\n");
            while(getchar()!='\n' && !feof(stdin));
            break;
        }
        push(item);
        break;

    case 2:
        pop();
        break;
    case 3:
        display();
        break;
    case 4:
        printf("Exiting the program .....\n");
        return 0;

    default:
        printf("Invalid option ,please enter the valid option from menu.\n");
    }
}
    return 0;
}

void push(int item){
    if(top==MAX_SIZE-1){
        printf("Stack is full.\n");
        return;
    }
    stack[++top]=item;
    printf("%d is inserted.\n",item);
}

void pop(){
    if(top<0){
        printf("Stack is underflow.\n");
        return;
    }
    printf("%d is poped.\n",stack[top]);
    top--;
}

void display(){
    if(top<0){
        printf("Stack is underflow.\n");
        return;
    }
    printf("Current Stack:");
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
    printf("\n");
}
 
// int topElement(){
//     return stack[top];
// }
