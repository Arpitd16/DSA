#include<stdio.h>
#include<stdlib.h>
//count sort is find the maximum number of elemant and this size create one array and enter the element in this array and return check it and sort them.
int findmax(int a[],int n)
{
    int max=0;
    int i;
    for(i=0;i<n;i++){
        if(a[i]>max)
        max=a[i];
    }
    return max;
}
void countsort(int a[],int  n){
    int i,j,max,*c;
    max=findmax(a,n);
    c=(int *)malloc((max+1)*sizeof(int));
    for(i=0;i<max+1;i++)
    c[i]=0;
    for(i=0;i<n;i++){
        c[a[i]]++;
    }
    i=0;j=0;
    while(j<max+1){
        if(c[j]>0)
        {
            a[i++]=j;
            c[j]--;
        }
        else
        j++;
    }
}
int main(){
    int a[]={11,13,7,12,16,9,24,5,10,3},n=10,i;
    countsort(a,n);
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n");
    return 0;
}