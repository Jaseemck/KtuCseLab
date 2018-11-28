#include<stdio.h>
#include<stdlib.h>

struct page{
    int val;
    int i;
    int count;
    struct page *next;
}*head;

int a[20],n,size;

int ishit(int a, int i){    
    struct page *p=head;
    while(p!=NULL){
        if(p->val==a){
            p->i=i;
            p->count++;
            return 1;
        }
        p=p->next;
    }
    return 0;
}

void findlfu(struct page *temp){
    struct page *p=head,*t=head;
    int min=head->count;
    int mini;
    while(p->next!=NULL){
        if(p->next->count<min){
            t=p;
            min=p->next->count;
        }
        p=p->next;
    }
    mini=t->next->i;
    p=head;
    while(p->next!=NULL){
        if((p->next->count==min)&&(p->next->i)<mini){
            t=p;
        }
        p=p->next;
    }
    if((head->count==min)&&(head->i < t->next->i)){
        t=head;
    }
    if(t==head){
        head=head->next;
        free(t);
        temp->next=head;
        head=temp;
    }else{
        struct page *q=t->next;
        temp->next=q->next;
        t->next=temp;
        free(q);
    }
}

void lfu(){
    int i,flag,fault=0,count;
    struct page *p,*q;
    for(i=0;i<n;i++){
        flag=0;
        if(head==NULL){
            fault++;
            struct page *temp=(struct page*)malloc(sizeof(struct page));
            temp->val=a[i];
            temp->count=1;
            temp->i=i;
            temp->next=NULL;
            head=temp;
            flag=1;
        }else{
            flag=ishit(a[i],i);
        }
        if(flag==0){
            count=0;
            fault++;
            struct page *temp=(struct page*)malloc(sizeof(struct page));
            temp->val=a[i];
            temp->next=NULL;
            temp->count=1;
            temp->i=i;
            p=head;
            while(p->next!=NULL){
                count++;
                p=p->next;
            }
            if(count!=size-1){
                p->next=temp;
            }else{
                findlfu(temp);
            }
        }
        p=head;
        printf("\n");
        while(p!=NULL){
            printf("%d-->",p->val);
            p=p->next;
        }
    }
    printf("\nNumber of faults = %d\n",fault);
}

void main(){
    head=NULL;
    printf("\nEnter the number of pages: ");
    scanf("%d",&n);
    printf("\nEnter the frame size: ");
    scanf("%d",&size);
    printf("\nEnter the pages: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    lfu();
}
