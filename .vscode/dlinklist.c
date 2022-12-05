#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node  *pre;
    int data;
    struct node *next;
}*first=NULL;
void create(int a[],int n){
    struct node *last,*t;
    int i;
    first=(struct node*)malloc(sizeof(struct node));
    first->data=a[0];
    first->pre=first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=last->next;
        t->pre=last;
        last->next=t;
        last=t;
    }
}
void dispaly(struct node *p){
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int length(struct node *p){
    int le=0;
    while (p)
    {
        le++;
        p=p->next;
    }
    return le;
}
void insert(struct node *p,int index ,int x){
    struct node *t;
    int i;
    if(index<0 || index>length(p))
    return ;
    if(index==0){
        t=(struct node*)malloc(sizeof(struct node));
        t->data=x;
        t->pre=NULL;
        t->next=first;
        first->pre=t;
        first=t;
        }
        else{
            for(i=0;i<index-1;i++)p=p->next;
            t=(struct node*)malloc(sizeof(struct node));
            t->data=x;
            t->pre=p;
            t->next=p->next;
            if(p->next)p->next->pre=t;
            p->next=t;
        }
}
int delete(struct node *p,int index){
    int x=-1,i;
    if(index<1 || index>length(p))
    return -1;
    if(index==1){
        first=first->next;
        if(first)first->pre=NULL;
        x=p->data;
        free(p);
    }
    else{
        for(i=0;i<index-1;i++)
        p=p->next;
        p->pre->next=p->next;
        if(p->next)
        p->next->pre=p->pre;
        x=p->data;
        free(p);
    }
    return x;
}
void reverse(struct node *p){
    struct node *temp;
    while(p!=NULL){
        temp=p->next;
        p->next=p->pre;
        p->pre=temp;
        p=p->pre;
        if(p!=NULL && p->next==NULL)
        first=p;
    }
}
int main(){
     int a[]={1,3,5,7,9};
    create(a,5);
    reverse(first);
    dispaly(first);
    return 0;
}