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
int main()
{
    treecreate();
    printf("pre order\n");
    preorder(root);
    printf("\npost order\n");
    postorder(root);
    return 0;
}