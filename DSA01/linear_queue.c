

#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define the maximum size of the queue

// Global variables
int queue[MAX];
int front = -1;
int rear = -1;

// Function Prototypes
void enqueue(int value);
void dequeue();
void display();
void peek();

int main() {
    int choice, value;

    while (1) {
        printf("\n\n*** LINEAR QUEUE MENU ***\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Peek (Front Element)\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// --- Function Definitions ---

void enqueue(int value) {
    // Check for Overflow
    if (rear == MAX - 1) {
        printf("!! OVERFLOW: Queue is full. Cannot insert %d !!\n", value);
    } else {
        // If this is the very first element
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("Successfully inserted: %d\n", value);
    }
}

void dequeue() {
    // Check for Underflow
    if (front == -1 || front > rear) {
        printf("!! UNDERFLOW: Queue is empty. Nothing to delete !!\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;

        // Reset pointers if the queue becomes empty after deletion
        // This helps mitigate the 'False Overflow' issue slightly
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty.\n");
    } else {
        printf("Current Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty.\n");
    } else {
        printf("Front element is: %d\n", queue[front]);
    }
}


/*

#include<stdio.h>
#include<stdlib.h>
#define N 5

int queue[N];
int front=-1,rear=-1;

void enqueue(int value){
// case1: check if queue is full
if(rear==N-1){
    printf("Queue is full.\n");
    return;
}

//case2: First Insertion or Empty
if(front==-1 && rear == -1){
    front=0;
    rear=0;
    queue[rear]=value;
    return;
}
// case3:Already exists
    rear++;
    queue[rear]=value;

}
//dequeue function
int dequeue(){
// case1: check if empty
if(front==-1 && rear==-1){
    printf(("Queue is empty.\n"));
    return -1;
}

//case2: single element
if(front==rear){
    int valueToReturn=queue[front];
    front=-1;
    rear=-1;
    return valueToReturn;
}

//case3:element already exists
int valueToReturn=queue[front];
front++;
return valueToReturn;

}

int isFull(){
    return rear==N-1;
}
int isEmpty(){
    return rear==-1 && front==-1;
}

int peek(){
    return queue[front];
}
void display(){
    if(front==-1 && rear ==-1){
        printf("Queue is Empty.\n");
        return;
    }
        printf("Current Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
}

int main(){
    dequeue();
    display();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("The peek value of the Queue: %d\n",peek());
    printf("Current Dequeue element is : %d",dequeue());
    return 0;
}

*/








































































