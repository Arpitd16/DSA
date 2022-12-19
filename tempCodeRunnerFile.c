#include<stdio.h>
#include<stdlib.h>
struct qu{
    int size;
    int front;
    int rear;
    int Q;
}*q;
void create(int size){
    q->size=size;
    q->front=q->rear=-1;
    q->Q=(int*)malloc(q->size*sizeof(int));
}
void display(){
    int i;
    for (i=q->fornt+1;1<=q->rear;i++)
    printf("%d\t",q->Q[i]);
    printf("\n");
}
void  enqueue(int x){
    if(q->rear==q->size-1)
    printf("queue is full");
    elae{
        q->rear++;
        q->Q[q->rear]=x;
    }
}
int dequeue(){
    int x=-1;
    if(q->rear==q->front)
    printf("queue is empty");
    else(
        q->front ++;
        x=q->Q[q->front];
    )
    return x;
}
int main(){
    struct qu q;
    create(5);
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
return 0;
}