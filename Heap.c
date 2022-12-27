#include<stdio.h>
void insert(int A[],int n){
int i=n,temp;
temp=A[i];
while(i>1 && A[i/2]<temp){
   A[i]=A[i/2];
   i=i/2;
}
A[i]=temp;
}
int delete(int a[],int n){
    int i,j,x,temp,val;
    val=a[1];
    a[1]=a[n];
    a[n]=val;
    i=1;
    j=2*i;
    while(j<n-1){
        if(a[j+1]>a[j])
        j=j+1;
        if(a[i]<a[j]){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;i=j;
            j=2*j;
        }
        else break;
    }
    return val;
}
int main(){
    int H[]={0,10,20,30,25,5,40,35};
    int i;
    for(i=2;i<=7;i++)
     insert(H,i);
     for ( i = 7; i>1; i--)
     {
        delete(H,i);
     }//if we comment his part it is mean it is nt sorted
     for(i=1;i<=7;i++)//if we do not comment delete part it is mean this printf is shown the sorted heap 
     printf("%d\t",H[i]);
     printf("\n");

     return 0;
}