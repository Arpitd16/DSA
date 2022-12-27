#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
int temp=*x;
*x=*y;
*y=temp;
}
void selectionsort(int a[],int n){
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        for(j=k=i;j<n;j++){
            if(a[j]<a[k]){
            k=j;
            }
        }
        swap( &a[i], &a[k]);
    }
}
int main(){
    int a[]={11,13,7,12,16,9,24,5,10,3},n=10,i;
    selectionsort(a,n);
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n");

    return 0;
}