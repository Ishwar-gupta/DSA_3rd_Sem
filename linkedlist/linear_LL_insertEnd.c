#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

struct Node *head =NULL;

//creating newNode
struct Node * newNode;

// Funx to create a newNode
struct Node* createNode(int val){
    newNode=(struct Node *)malloc(sizeof(struct Node));

    //if node is empty
    if(newNode == NULL){
        printf("Memory allocation Failed!!\n");
        exit(1);
    }

    // fufiling newNode with data and setting next to NULL
    newNode->data=val;
    newNode->next=NULL;

    return newNode;
}

//inserting newNode at the end of linked list
void insert_end(int val){

    newNode=createNode(val);

    if(head == NULL){
        head=newNode;
        return;
    }

    struct Node* temp=head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

//displaying the singly linked list
void displayNode(){
    struct Node* temp=head;
    if(temp==NULL){
        printf("List is Empty.\n");
        return;
    }
    printf("Singly linked lists: ");
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    insert_end(10);
    insert_end(20);
    insert_end(30);

    
    insert_begin(50);
    insert_begin(5);
    insert_begin(4);
    displayNode();
    return 0;
}