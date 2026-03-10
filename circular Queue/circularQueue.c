/*

#include <stdio.h>
#define maxsize 8

int item[maxsize];
int f = -1, r = -1;

int isFull()
{
    return ((r + 1) % maxsize == f);
}

int isEmpty()
{
    return (f == -1);
}

void Enqueue(int x)
{
    if (isFull())
    {
        printf("Queue is full\n");
        return;
    }

    if (isEmpty())
    {
        f = 0;
    }

    r = (r + 1) % maxsize;
    item[r] = x;

    printf("Enqueued: %d\n", x);
}

int Dequeue()
{
    int x;

    if (isEmpty())
    {
        printf("Queue is empty\n");
        return -1;
    }

    x = item[f];

    if (f == r)   // last element
    {
        f = r = -1;
    }
    else
    {
        f = (f + 1) % maxsize;
    }

    return x;
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = f;
    while (1)
    {
        printf("%d ", item[i]);
        if (i == r)
            break;
        i = (i + 1) % maxsize;
    }
    printf("\n");
}

int main()
{
    Enqueue(10);
    Enqueue(11);
    Enqueue(12);

    printf("Dequeued: %d\n", Dequeue());

    display();

    return 0;
}
*/
#include<stdio.h>
#define MAXSIZE 10

struct cqueue{
int front;
int rear;
int item[MAXSIZE];
};
typedef struct cqueue cq;

int isfull(cq *q){
    if(q->front == (q->rear+1)%MAXSIZE){
        return 1;
    }else{
        return 0;
    }
}


int isEmpty(cq *q){
    if(q->rear==q->front)
        return 1;
    else
        return 0;
}

void enqueue(cq *q){
    int x;
    printf("Enter Element:");
    scanf("%d",&x);

    if(isfull(q))
        printf("cqueue is full.\n");
    else{
        q->rear=(q->rear+1)%MAXSIZE;
        q->item[q->rear]=x;
    }
}

void dequeue(cq *q){
    int x;
    if(isEmpty(q)){
        printf("Nothing to delete.\n");
    }else{
        q->front=(q->front+1)%MAXSIZE;
        x=q->item[q->front];
        printf("Deleted item is %d \n",x);
    }

}

void traverse(cq *q){
    while(q->front !=q->rear){
        q->front=(q->front+1)%MAXSIZE;
        printf("%d ",q->item[q->front]);
        q->front=(q->front+1)%MAXSIZE;
        printf("%d ",q->item[q->front]);

    }
}

int main(){
cq q;
enqueue(&q);
enqueue(&q);
dequeue(&q);
traverse(&q);

return 0;
}



















