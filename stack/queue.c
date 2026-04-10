#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int front =-1,rear=-1;
int queue[MAX];

int isFull(){
    return rear == MAX-1;
}
int isEmpty(){
    return front == -1 && rear == -1;
}
//enqueue operation
void enqueue(int item){
    //case 1: if queue is empty
    if(isFull()){
        printf("Queue is Full.\n\n");
        return ;
    }

    //case 2: first insertion or empty

    if(isEmpty()){
        front=rear=0;
        queue[rear]=item;
        printf("%d is enqueued.\n",item);
        return;
    }
    //case 3: if already exists
    rear++;
    queue[rear]=item;
    printf("%d is enqueued.\n",item);
}

//dequeue opeation

int dequeue(){
    //case 1: check for empty
    if(isEmpty()){
        printf("Queue is Empty.\n");
        return -1;
    }
    //case 2:having only single element
    if(front==rear){
        int ValueToReturn =queue[front];
        front = rear = -1;
        return ValueToReturn ;
    }
    //case 3: element already exists

    int valueToReturn =queue[front];
    front++;
    return valueToReturn;
}

void display(){
    if(isEmpty()){
        printf("Queue is Empty.\n");
        return ;
    }
    printf("Current Queue is : ");
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}


int peek(){
    if(isEmpty()){
        printf("Queue is Empty.\n");
        return -1;
    }
    return queue[front];
}

int main(){
    display();
    dequeue();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    dequeue();
    dequeue();
    // dequeue();
    // dequeue();
    // dequeue();
    // dequeue();
    printf("Top Element of Queue is %d \n",peek());
    display();

    return 0;
}