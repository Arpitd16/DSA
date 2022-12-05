//circuler linklist
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head;
void create(int a[], int n)
{
    int i;
    struct node *last, *t;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = a[0];
    head->next = head;
    last = head;
    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(struct node *h)
{
    do
    {
        printf("%d ", h->data);
        h = h->next;

    } while (h != head);
    printf("\n");
}
void rdisplay(struct node *h)
{
    static int flg = 0;
    if (h != head || flg == 0)
    {
        flg = 1;
        printf("%d", h->data);
        rdisplay(h->next);
    }
    flg = 0;
}
int length(struct node *h)
{
    int l = 0;
    do
    {
        l++;
        h = h->next;
    } while (h != head);
    return l;
}
void Insert(struct node *h, int index, int x)
{
    struct node *t;
    int i;
    if (index < 0 || index > length(h))
        return;
    if (index == 0)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while (h->next != head)
                h = h->next;
            h->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            h = h->next;
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->next = h->next;
        h->next = t;
    }
}
int Delete(struct node *p, int index)
{
    struct node *q;
    int i, x;
    if (index < 0 || index > length(head))
        return -1;
    if (index == 1)
    {
        while (p->next != head)
            p = p->next;
        x = head->data;
        if (head == p)
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else
    {
        for (i = 0; i < index - 2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}
int main()
{
    int a[] = {1, 3, 5, 7, 9};
    create(a, 5);
     Delete(head,1);
    Insert(head,2,4);
    display(head);
    return 0;
}