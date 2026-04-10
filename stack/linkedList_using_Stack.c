#include<stdio.h>
#include<stdlib.h>

struct Stack{
   int data;
   struct Stack *next;
};

struct Stack *top = NULL;

// Push Operation
void push(int item){

    // memory allocation
    struct Stack * newNode =(struct Stack*)malloc(sizeof(struct Stack));
    newNode->data=item;
    newNode->next=top;
    top=newNode;
    printf("%d is pushed into stack.\n",item);
}

//Pop Operation
void pop(){
    if(top==NULL){
        printf("Stack Underflow.\n");
        return;
    }
    struct Stack *temp=top;
    top = top->next;
    printf("%d is popped from stack.\n",temp->data);
    free(temp);
}

//displaying the current stack element
void display(){
    //check null condition
    if(top == NULL){
        printf("Stack Underflow.\n");
        return;
    }
    struct Stack *temp=top;
    // if elements exists
    printf("Current Stack Elements : ");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int peek(struct Stack* top) {
    // Check if stack is empty
    if (top == NULL) {
        printf("Stack is Empty.\n");
        return -1;
    }

    // Return top element
    return top->data;
}

int main(){
    display();
    push(10);
    push(50);
    push(30);
    push(99);
    pop();
    printf("\n****************************** \nTop Element of the stack is %d.\n ******************************\n",peek(top));
    display();
    
    return 0;
}
