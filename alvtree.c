#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *lchild;
    struct node *rchild;
    int data;
    int height;
} *root = NULL;
int nodeheight(struct node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}
int balancefactor(struct node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl - hr;
}
struct node *llrotation(struct node *p)
{
    struct node *pl = p->lchild;
    struct node *plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;
    p->height = nodeheight(p);
    pl->height = nodeheight(pl);
    if (root == p)
        root = pl;
    return pl;
}
struct node *lrrotation(struct node *p)
{
    struct node *pl = p->lchild;
    struct node *plr = pl->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;
    pl->height = nodeheight(pl);
    p->height = nodeheight(p);
    plr->height = nodeheight(plr);
    if (root == p)
        root = plr;
    return plr;
}
struct node *rrrotation(struct node *p)
{
    return NULL;
}
struct node *rlrotation(struct node *p)
{
    return NULL;
}
struct node *rinsert(struct node *p, int key)
{
    struct node *t = NULL;
    if (t == NULL)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
        p->lchild = rinsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = rinsert(p->rchild, key);
    p->height = nodeheight(p);
    if (balancefactor(p) == 2 && balancefactor(p->lchild) == 1)
        return llrotation(p);
    else if (balancefactor(p) == 2 && balancefactor(p->lchild) == -1)
        return lrrotation(p);
    else if (balancefactor(p) == -2 && balancefactor(p->rchild) == -1)
        return rrrotation(p);
    else if (balancefactor(p) == -2 && balancefactor(p->rchild) == 1)
        return rlrotation(p);
    return p;
}
int main()
{
    root = rinsert(root, 50);
    rinsert(root, 10);
    rinsert(root, 20);
    return 0;
}