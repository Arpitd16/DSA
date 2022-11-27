#include <stdio.h>
#include <stdlib.h>
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
int get(struct array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
        return arr->A[index];
    return -1;
}
void set(struct array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
        arr->A[index] = x;
}
int max(struct array arr)
{
    int max = arr.A[0];
    int i;
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}
int min(struct array arr)
{
    int min = arr.A[0];
    int i;
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}
int sum(struct array arr)
{
    int s = 0;
    int i;
    for (i = 0; i < arr.length; i++)
    {
        s += arr.A[i];
        /* code */
    }
    return s;
}
float avg(struct array arr)
{

    return (float)sum(arr) / arr.length;
}
void reverse(struct array *arr)
{
    int *b;
    int i, j;
    b = (int *)malloc(arr->length * sizeof(int));
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
        b[j] = arr->A[i];
    for (i = 0; i < arr->length; i++)
        arr->A[i] = b[i];
}
void reverse2(struct array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}
void insertsort(struct array *arr, int x)
{
    int i = arr->length;
    if (arr->length == arr->size)
        return;
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}
int issorted(struct array arr)
{
    int i;
    for (i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    }
    return 1;
}
void rearrange(struct array *arr)
{
    int i, j;
    i = 0;
    j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] >= 0)
            j--;
        if (i < j)
            swap(&arr->A[i], &arr->A[j]);
    }
}
struct array *merge(struct array *arr1, struct array
                                            *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct array *arr3 = (struct array
                              *)malloc(sizeof(struct array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
    return arr3;
}
struct array *uniono(struct array *arr1, struct array
                                             *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct array *arr3 = (struct array
                              *)malloc(sizeof(struct array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}
struct array *intersection(struct array *arr1, struct
                           array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct array *arr3 = (struct array
                              *)malloc(sizeof(struct array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else if (arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}
struct array *Difference(struct array *arr1, struct
                         array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct array *arr3 = (struct array
                              *)malloc(sizeof(struct array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}
int main()
{
    struct array arr1;
    int ch;
    int x, index;
    printf("Enter Size of Array");
    scanf("%d", &arr1.size);
    /*arr1.A=*/(int *)malloc(arr1.size * sizeof(int));
    arr1.length = 0;
    do
    {
        printf("\n\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6.Exit\n");
        printf("enter you choice ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter an element and index");
            scanf("%d%d", &x, &index);
            insert(&arr1, index, x);
            break;
        case 2:
            printf("Enter index ");
            scanf("%d", &index);
            x = delete (&arr1, index);
            printf("Deleted Element is %d\n", x);
            break;
        case 3:
            printf("Enter element to search ");
            scanf("%d", &x);
            index = linearserch(&arr1, x);
            printf("Element index %d", index);
            break;
        case 4:
            printf("Sum is %d\n", sum(arr1));
            break;
        case 5:
            display(arr1);
        }
    } while (ch < 6);
    return 0;
}

// this for first four five function
//  struct array arr = {{2, 4, 6, 8, 16, 24}, 10, 6};
//  printf("%d\n", binaryserch(arr, 16));
//  // printf("%d",delete(&arr,2));
//  // printf("%d\n",linearserch(&arr,6));
//  // append(&arr, 6);
//  // insert(&arr, 0, 9);
//  display(arr);
// you seee one video of the binarysearch in video