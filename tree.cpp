#include <iostream>
#include <stdlib.h>
#include "queuefortree.cpp"
using namespace std;
class tree
{

    node *root;

public:
    tree() { root = NULL; }
    void createtree();
    void preorder() { preorder(root); }
    void preorder(node *p);
    void postorder() { postorder(root); }
    void postorder(node *p);
    void inorder() { inorder(root); }
    void inorder(node *p);
    void levelorder() { levelorder(root); }
    void levelorder(node *p);
    int hight() { return hight(root); }
    int hight(node *root);
};
void tree::createtree()
{
    node *t, *p;
    int x;
    queue q(100);
    printf("enter the value of root");
    scanf("%d", &x);
    root = new node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    while (!q.isempty())
    {
        p = q.dequeue();
        printf("enter left child of %d:", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        printf("enter right child of %d:", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}
void tree::preorder(struct node *p)
{
    if (p)
    {
        printf("%d\t", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void tree::inorder(struct node *p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d\t", p->data);
        inorder(p->rchild);
    }
}
void tree::postorder(struct node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d\t", p->data);
    }
}
void tree::levelorder(struct node *p)
{
    queue q(100);
    printf("%d\t", root->data);
    q.enqueue(root);
    while (!q.isempty())
    {
        root = q.dequeue();
        if (root->lchild)
        {
            printf("%d\t", root->lchild->data);
            q.enqueue(root->lchild);
        }
        if (root->rchild)
        {
            printf("%d\t", root->rchild->data);
            q.enqueue(root->rchild);
        }
    }
}
int tree::hight(struct node *root)
{
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = hight(root->lchild);
    y = hight(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}
int main()
{
    tree t;
    t.createtree();
    cout << "preorder\n";
    t.preorder();
    cout << "postorder\n";
    t.postorder();
    printf("\n");
    t.levelorder();
    printf("\nthe value of %d\n", t.hight());
    return 0;
}