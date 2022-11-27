#include <stdio.h>

struct array
{
    int A[10];
    int size;
    int length;
};
void display(struct array arr)
{
    int i;
    printf("array element: \n");
    for (i = 0; i < arr.length; i++)
    {
        printf("%d", arr.A[i]);
        /* code */
    }
}
void append(struct array *arr, int x)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}
void swap(int *a, int *b)
{
    int teamp;
    teamp = *a;
    *a = *b;
    *b = teamp;
}
int linearserch(struct array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}
void insert(struct array *arr, int index, int x)
{
    int i;
    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;
        arr->length++;
    }
}
int delete(struct array *arr, int index)
{
    int x = 0;
    int i;
    if (index >= 0 && index <= arr->length)
    {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;
        return x;
    }
    return 0;
}
int binaryserch(struct array arr, int key)
{
    int l, h, mid;
    l = 0;
    h = arr.length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key = arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
int rbinserch(int a[], int l, int h, int key)
{
    int mid = 0;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return rbinserch(a, l, mid - 1, key);
    }
    else
        return rbinserch(a, mid + 1, h, key);
    return -1;
}
int main()
{
    struct array arr = {{2, 4, 6, 8, 16, 24}, 10, 6};
    printf("%d\n", binaryserch(arr, 16));
    // printf("%d",delete(&arr,2));
    // printf("%d\n",linearserch(&arr,6));
    // append(&arr, 6);
    // insert(&arr, 0, 9);
    display(arr);
    return 0;
}
//you seee one video of the binarysearch in video