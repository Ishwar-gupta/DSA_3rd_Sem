

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

static struct Node *head = NULL;

static void insert_end(int value) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    node->data = value;
    node->next = NULL;

    if (head == NULL) {
        head = node;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

static void display(void) {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Singly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(void) {
    insert_end(10);
    insert_end(20);
    insert_end(30);

    display();

    return 0;
}

/*
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info;
    struct Node *next;
};

struct Node *head =NULL;

void insert_end(int val){
    struct Node *newNode=(struct  Node*)malloc(sizeof(struct Node));
    //check if node is null
    if(newNode == NULL){
        printf("\n Memory Allocation Failed!!!.\n");
        return;
    }

    //first insertion
    newNode->info=val;
    newNode->next=NULL;

    //check if head is empty then make first newNode as head
    if(head == NULL){
        head=newNode;
        return;
    }

    struct Node *temp=head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

//traversing the linked list
void displayList(){
    //make temp of head for traverse and updation
    struct Node *temp=head;
    //check if list is empty or not
    if(head==NULL){
        printf("\nOops!! The list is empty.\n");
        return;
    }

    //traversing one by one 
    printf("Singly linked list are :");
    while (temp != NULL)
    {
        printf("%d ",temp->info);
        temp=temp->next;
    }
    printf("\n");
    
}

int main(){
    insert_end(60);
    insert_end(60);
    insert_end(60);
   
    displayList();
    return 0;
}
*/