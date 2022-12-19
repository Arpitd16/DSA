#include <iostream>
using namespace std;
class queue
{
private:
    int front;
    int rear;
    int size;
    int *Q;

public:
    queue()
    {
        front = rear = -1;
        size = 5;
        Q = new int[size];
    }
    queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new int[this->size];
    }
    void enqueue(int x);
    int dequeue();
    void display();
};
void queue::enqueue(int x)
{
    if (rear == size - 1)
        cout << "queue is full" << endl;
    else
    {
        rear++;
        Q[rear] = x;
    }
}
int queue::dequeue()
{
    int x = -1;
    if (rear = size - 1)
        cout << "queue is empty" << endl;
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}
void queue::display()
{
    int i;
    for (i = front + 1; i <= rear; i++)
        cout << "" << Q[i];
}
int main()
{
    queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    return 0;
}