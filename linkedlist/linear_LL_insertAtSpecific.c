#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

// create node
struct Node* createNode(int val){

    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if(newNode == NULL){
        printf("Memory Allocation Failed!!");
        exit(1);
    }

    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

// push front
void push_front(int val){

    struct Node *newNode = createNode(val);

    newNode->next = head;
    head = newNode;

    if(tail == NULL)
        tail = newNode;
}

// insert at position
void insert_Node_At_Specific(int val,int pos){

    if(pos < 0){
        printf("Invalid position!!\n");
        return;
    }

    if(pos == 0){
        push_front(val);
        return;
    }

    struct Node* temp = head;

    for(int i=0;i<pos-1;i++){

        if(temp == NULL){
            printf("Invalid position!!\n");
            return;
        }

        temp = temp->next;
    }

    struct Node *newNode = createNode(val);

    newNode->next = temp->next;
    temp->next = newNode;
}

// display
void displayNode(){

    struct Node* temp=head;

    if(temp==NULL){
        printf("List is Empty.\n");
        return;
    }

    printf("Singly linked list: ");

    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }

    printf("NULL\n");
}

int main(){

    insert_Node_At_Specific(4,0);
    insert_Node_At_Specific(10,1);
    insert_Node_At_Specific(20,2);

    displayNode();

    return 0;
}