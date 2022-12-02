#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;

} *first = NULL;
void create(int A[], int n)
{
    int i;
    struct node *t, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 0; i < n; i++)
    {
        t= (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
void RDisplay(struct node *p)
{
if(p!=NULL)
{
RDisplay(p->next);
printf("%d ",p->data);
}
}
int main(){
   int A[]={3,4,9,15,10};
    create(A,5);
    display(first);
    RDisplay(first);
    return 0;
}