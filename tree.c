#include <stdio.h>
#include <stdlib.h>
#include "queuefortree.c"
#include "stackfortree.c"

struct node *root = NULL;
void treecreate()
{
    struct node *t, *p;
    int x;
    struct queue q;
    create(&q, 100);
    printf("enter the value of root");
    scanf("%d", &x);
    root = (struct node *)malloc(sizeof(struct node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    while (!isempty(q))
    {
        p = dequeue(&q);
        printf("enter left child of %d:", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("enter right child of %d:", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}
void preorder(struct node *p)
{
    if (p)
    {
        printf("%d\t", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void inorder(struct node *p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d\t", p->data);
        inorder(p->rchild);
    }
}
void postorder(struct node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d\t", p->data);
    }
}
void ipreorder(struct node *p)
{
    struct stack stk;
    stackcreate(&stk, 100);
    while (p || !isemptystack(stk))
    {
        if (p)
        {
            printf("%d ", p->data);
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            p = p->rchild;
        }
    }
}
void iinorder(struct node *p)
{
    struct stack stk;
    stackcreate(&stk, 100);
    while (p || !isemptystack(stk))
    {
        if (p)
        {
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}
void levelorder(struct node *root)
{
    struct queue q;
    create(&q, 100);
    printf("%d", root->data);
    enqueue(&q, root);
    while (!isempty(q))
    {
        root = dequeue(&q);
        if (root->lchild)
        {
            printf("%d", root->lchild->data);
            enqueue(&q, root->lchild);
        }
        if (root->rchild)
        {
            printf("%d", root->rchild->data);
            enqueue(&q, root->rchild);
        }
    }
}
int count(struct node *root)
{
    if (root)
        return count(root->lchild) + count(root->rchild) + 1;
    return 0;
}
int height(struct node *root)
{
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = height(root->lchild);
    y = height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}
int main()
{
    treecreate();
    printf("pre order\n");
    ipreorder(root);
    printf("\ninorder order\n");
    iinorder(root);
    printf("\nlevel order\n");
    levelorder(root);
    printf("\n%d", height(root));
    return 0;
}