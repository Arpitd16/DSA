#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;

} *first = NULL, *second = NULL, *third = NULL;
void create1(int A[], int n)//create linklist
{
    int i;
    struct node *t, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void create2(int B[], int n)
{
    int i;
    struct node *t, *last;
    second = (struct node *)malloc(sizeof(struct node));
    second->data = B[0];
    second->next = NULL;
    last = second;
    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = B[i];
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
void RDisplay(struct node *p) // recursion display
{
    if (p != NULL)
    {
        RDisplay(p->next);
        printf("%d ", p->data);
    }
}
int count(struct node *p)//count linklist
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}
int rcount(struct node *p)
{

    if (p != NULL)
        return rcount(p->next) + 1;
    else
        return 0;
}
int sum(struct node *p)
{
    int s = 0;
    while (p != NULL)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}
int rsum(struct node *p)
{
    if (p == NULL)
        return 0;
    else
        return rsum(p->next) + p->data;
}
// int max(struct node *p)
// {
//     int max = ; // value is INT32_MIN
//     while (p)
//     {
//         if (max < p->data)
//             p->data;
//         p = p->next;
//     }
//     return max;
// }
// int rmax(struct node *p)
// {
//     int x = 0;
//     if (p == 0)
//         ;
//     return // INT64_MIN;
//         x = rmax(p->next);
//     if (x > p->data)
//         return x;
//     else
//         return p->data;
// }
struct node *lsearch(struct node *p, int key)//element serch karva
{
    struct node *q;
    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}
struct node *rsearch(struct node *p, int key)
{
    if (p == NULL)
    {
        return NULL;
        if (key == p->data)
            return p;
        return rsearch(p->next, key);
    }
}
void insert(struct node *p, int index, int x)
{
    struct node *t;
    int i;
    if (index < 0 || index > count(p))
        return;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}
void sortinsert(struct node *p, int x)//sorted linklist ma insert karva
{
    struct node *q, *t = NULL;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    if (first == NULL)
        first = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}
int delete(struct node *p, int index)//delete
{
    struct node *q = NULL;
    int x = -1, i;
    if (index < 1 || index > count(p))
        return -1;
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}
int issorted(struct node *p)//cheking the link it is sorted ??
{
    int x = -65536;
    while (p != NULL)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}
void removeduplicate(struct node *p)//remove element
{
    struct node *q = p->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}
int reverse1(struct node *p)
{
    int *A, i = 0;
    struct node *q = p;
    A = (int *)malloc(sizeof(int) * count(p));//arrray create and reverse create array and du=isplay by dicrement of i
    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;//in this meaning the p call strating of the linklist
    i--;
    while (q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}
void reverse2(struct node *p)//it is sliding pointer of the node
{
    struct node *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;//pointing to the reverse of the linklist and print thm
    }
    first = q;
}
void reverse3(struct node *q, struct node *p)
{

    if (p)
    {
        reverse3(p, p->next);
        p->next = q;//this is same of pointing of the linklist
    }
    else
        first = q;
}
int merge(struct node *p, struct node *q)//merge two linklist
{
    struct node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;//becaue we will going into new link list and same liklist it is not dicided that we declear last node is null
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
        last->next = p;
    if (q)
        last->next = q;
}
int isloop(struct node *f)//it is ths type of loop that so the pointer will meet in the lisk list by two 
{
    struct node *p, *q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;

    } while (p && q && p != q);
    if (p == q)
        return 1; 
    else
        return 0;
}
int main()
{
    // struct node *teamp;
    int A[] = {3, 4, 9, 10, 15};
    create1(A, 5);
    struct node *t1, *t2;

    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;
    printf("%d\n", isloop(first));
    // int A[] = {10, 20, 40, 50, 60};
    // int B[] = {5, 8, 15, 25, 30, 32};
    // create1(A, 5);
    // create2(B, 6);
    // merge(first, second);
    // reverse3(NULL,first);
    // removeduplicate(first);
    // printf("%d\n",issorted(first));
    // delete (first, 2);
    //  print("%d\n"delete(first,2));//it is not run.why it is not running askingh to  harit you ramember that
    //   insert(first, 0, 5);
    //   printf("%d\n", rcount(first));
    //   printf("%d\n", rsum(first));
    //   printf ("%d\n",max(first));
    //   teamp = rsearch(first, 9);
    //   printf("%d\n", teamp->data);
    //  sortinsert(first,5);
    //  printf("%d\n", sortinsert(first, 5));//it is not run
    // display(third);
    // RDisplay(first);

    return 0;
}
// r meaning is recursion it is solved by recursion.
