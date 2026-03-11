#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};
struct Node * head = NULL;

// creating newNode
struct Node* createNode(int val){
    struct Node* newNode ;
    newNode=(struct Node *)malloc(sizeof(struct Node));

    if(newNode == NULL){
        printf("Memory Allocation Failed!!");
        exit(1);
    }

    newNode->data=val;
    newNode->next=NULL;

    return newNode;
}

//inserting at begin

void insert_begin(int val){
    struct Node* newNode = createNode(val);
    
    newNode->next=head;
    head=newNode;
}

void delete_front(){
    if (head == NULL){
        printf("List is empty!!\n");
        return;
    }
    struct Node* temp=head;
    head=head->next;
    // temp->next=NULL;
    free(temp);
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
    insert_begin(10);
    insert_begin(20);
    insert_begin(50);
    insert_begin(90);
    delete_front();
    displayNode();
    return 0;
}
