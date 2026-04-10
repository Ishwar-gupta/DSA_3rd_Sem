#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int front = -1;
int rear = -1;

int cirqueue[MAX];

// check if full
int isFull(){
    return (rear + 1) % MAX == front;
}

// check if empty
int isEmpty(){
    return front == -1 && rear == -1;
}

// enqueue
void enqueue(int item){
    if(isFull()){
        printf("Circular Queue is full.\n");
        return;
    }

    if(isEmpty()){
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    cirqueue[rear] = item;
    printf("%d is enqueued.\n", item);
}

// dequeue
int dequeue(){
    if(isEmpty()){
        printf("Circular Queue is empty.\n");
        return -1;
    }

    int value = cirqueue[front];

    if(front == rear){
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }

    return value;
}

// display
void display(){
    if(isEmpty()){
        printf("Circular Queue is empty.\n");
        return;
    }

    printf("Current circular queue is: ");

    int i = front;
    while(1){
        printf("%d ", cirqueue[i]);
        if(i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// peek
void peek(){
    if(isEmpty()){
        printf("Circular Queue is empty.\n");
        return;
    }
    printf("Front element is %d\n", cirqueue[front]);
}

// main
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    dequeue();
    enqueue(60);

    display();
    peek();

    return 0;
}