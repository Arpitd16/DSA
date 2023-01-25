#include <stdio.h>
#define size 10
int hash(int key)
{
    return key % size;
}
int prob(int h[], int key)
{
    int index = hash(key);
    int i = 0;
    while (h[(index + i) % size] != 0)
        i++;
    return (index + i) % size;
}
void insert(int h[], int key)
{
    int index = hash(key);
    if (h[index] != 0)
        index = prob(h, key);
    h[index] = key;
}
int serch(int h[], int key)
{
    int index = hash(key);
    int i = 0;
    while (h[(index + i) % size] != key)
        i++;
    return (index + i) % size;
}
int main()
{
    int h[10] = {0};
    insert(h, 20);
    insert(h, 25);
    insert(h, 35);
    insert(h, 24);
    printf("\n key  fornd at %d", serch(h, 35));
}