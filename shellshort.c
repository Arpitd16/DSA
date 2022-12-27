#include<stdio.h>
#include<stdlib.h>
//shell shor is gap/2 type of shorting of the array
//bin bucket is linklist type of shorting 
//radix is the modulo of the number and divison by(1,100,1000......)
void shellshort(int a[],int n)
{
    int gap,i,j,temp;
    for(gap=n/2;gap>=1;gap/=2)
    {
        for(i=gap;i<n;i++){
            temp=a[i];
            j=i-gap;
            while(j>=0 && a[j]>temp)
            {
                a[j+gap]=a[j];
                j=j-gap;
            }
            a[j+gap]=temp;
        }
    }
}
int main(){
     int a[]={11,13,7,12,16,9,24,5,10,3},n=10,i;
     shellshort(a,n);
     for(i=0;i<n;i++){
        printf("%d ",a[i]);
    
     }
     printf("\n");
     return 0;
}