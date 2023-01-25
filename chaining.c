#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insertsorted(struct node **h, int x)
{
    struct node *t, *q = NULL, *p = *h;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    if (*h = NULL)
        *h = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == *h)
        {
            t->next = *h;
            *h = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}
struct node *serch(struct node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
            {
                return  p;
                }
        p = p->next;
    }
    return NULL;
}
int hash(int key)
{
    return key % 10;
}
void insert(struct node *h[], int key)
{
    int index = hash(key);
    insertsorted(&h[index], key);
}
int main()
{
    struct node *h[10];
    struct node *temp;
    int i;
    for (i = 0; i < 10; i++)
        h[i] = NULL;
    insert(h, 15);
    insert(h, 25);
    insert(h, 35);
    temp = serch(h[hash(25)], 25);
    printf("%d  ", temp->data);
    return 0;
}