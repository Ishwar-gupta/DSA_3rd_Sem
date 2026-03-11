#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

struct Node *head , *tail =NULL;

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

// Inserting newNode at the beginning of the Node
void insert_begin(int val){

    newNode=createNode(val);

    if(head == NULL){
        head = tail = newNode;
        return;
    }

    //addressing assigning and updating head pointer
    newNode->next = head;
    head = newNode;
}
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
    
    insert_begin(50);
    insert_begin(5);
    insert_begin(4);

    displayNode();
    return 0;
}