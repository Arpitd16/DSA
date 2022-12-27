#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *lchild;
    struct node *rchild;
    int data;
};
struct queue
{
    int size;
    int front;
    int rear;
    struct node **Q;
};
void create(struct queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (struct node **)malloc(q->size * sizeof(struct node *));
}
void enqueue(struct queue *q, struct node *x)
{
    if (q->rear == q->size - 1)
        printf("queue is full");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}
struct node *dequeue(struct queue *q)
{
    struct node *x = NULL;
    if (q->front == q->rear)
        printf("queue is empty");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}
int isempty(struct queue q)
{
    return q.front == q.rear;
}