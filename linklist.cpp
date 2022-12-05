#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class linklist
{
private:
    node *first;

public:
    linklist() { first = NULL; }
    linklist(int A[], int n);
    ~linklist();
    void display();
    void insert(int index, int x);
    int length();
    int Delete(int index);
};
linklist::linklist(int A[], int n)
{
    node *last, *t;
    int i = 0;
    first = new node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n;i++)
    {
        t = new node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
linklist::~linklist()
{
    node *p = first;
    while (first)
    {
        first = first->next;
        delete (p);
        p = first;
    }
}
void linklist::display()
{
    node *p = first;
    while (p)
    {
        cout << p->data << "";
        p = p->next;
    }
    cout << endl;
}
int linklist::length()
{
    node *p = first;
    int le = 0;
    while (p)
    {
        le++;
        p = p->next;
    }
    return le;
}
void linklist::insert(int index, int x)
{
    node *t, *p = first;
    if (index < 0 || index > length())
        return;
    t = new node;
    t->data = x;
    t->next = NULL;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 1; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}
int linklist::Delete(int index)
{
    node *p, *q = NULL;
    int x = -1;
    if (index < 1 || index > length())
        return -1;
    if (index == 1)
    {
        p = first;
        first = first->next;
        x = p->data;
        delete (p);
    }
    else
    {
        p = first;
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    linklist l(A, 5);
    l.insert(3, 10);
    l.Delete(1);
    
    l.display();
    return 0;
}