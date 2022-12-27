#include <stdio.h>
#include <stdlib.h>
void merge(int a[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[100];
    while (i <= mid && j <= h)
    {
        if (a[i] < a[j])
            B[k++] = a[i++];
        else
            B[k++] = a[j++];
    }
    for (; i <= mid; i++)
        B[k++] = a[i];
    for (; j <= h; j++)
        B[k++] = a[j];
    for (i = l; i <= h; i++)
        a[i] = B[i];
}
void imergesort(int a[], int n)//it merge of sorting it is a p*2 element merge of them and sort them .
{
    int p, l, h, mid, i;
    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 <n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(a, l, mid, h);
        }
    }
    if (p / 2 < n)
        merge(a, 0, p / 2-1, n-1);
}
//recurtion
void recurtionsort(int a[],int l,int h){//it is recution of the function and sort them .
    int mid;
    if(l<h){
        mid=(l+h)/2;
        recurtionsort(a,l,mid);
        recurtionsort(a,mid+1,h);
        merge(a,l,mid,h);
    }
}
int main()
{
    int a[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;
    imergesort(a, n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    // recurtionsort(a,0,n-1);
    // for(i=0;i<10;i++){
    //     printf("%d ",a[i]);
    // }

    return 0;
}