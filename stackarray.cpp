// array using by stack
#include <iostream>
using namespace std;
template <class T>
class stack
{
private:
    T *st;
    int size;
    int top;

public:
    stack()
    {
        size = 10;
        top = -1;
        st = new T[size];
    }
    stack(int size)
    {
        this->size = size;
        top = -1;
        st = new T[this->size];
    }
    void push(T x);
    T pop();
    T peek(int index);
    int stacktop();
    int isempty();
    int isfull();
    void display();
};
template <class T>
void stack<T>::push(T x)
{
    if (isfull())
        cout << "stack is overflow" << endl;
    else
    {
        top++;
        st[top] = x;
    }
}
template <class T>
T stack<T>::pop()
{
    T x = -1;
    if (isempty())
        cout << "stack underflow" << endl;
    else
    {
        x = st[top];
        top--;
    }
    return x;
}
template <class T>
T stack<T>::peek(int index)
{
    T x = -1;
    if (top - index + 1 < 0)
        cout << "invalied index" << endl;
    else
    {
        x = st[top - index + 1];
    }
    return x;
}
template <class T>
int stack<T>::stacktop()
{
    if (isempty())
        return -1;
    return st[top];
}
template <class T>
int stack<T>::isempty()
{
    return top == -1;
}
template <class T>
int stack<T>::isfull()
{
    return top == size - 1;
}
template <class T>
void stack<T>::display()
{
    for (int i = top; i >= 0; i--)
        cout << st[i] << "";
    cout << endl;
}
int main()
{
    stack<char> stk(6);
    stk.push('y');
    stk.push('t');
    stk.push('i');
    stk.push('p');
    stk.push('r');
    stk.push('a');
    cout << stk.peek(1) << endl;
    stk.display();
    return 0;
}