#include<stdio.h>
#include<stdlib.h>

struct page{
    int val,i;
    struct page *next;
}*head;

int a[20],n,size;

void remlru(struct page *q){
    int flag,mini;
    struct page *p=head,*t,*rem;
    mini=head->i;
    flag=0;
    while(p->next!=NULL){
        if(p->next->i<mini){
            t=p;
            mini=p->next->i;
            flag=1;
        }
        p=p->next;
    }
    if(flag==0){
        //remove head
        p=head;
        head=head->next;
        q->next=head;
        head=q;
        free(p);
    }else{
        //remove t->next
        rem=t->next;
        q->next=rem->next;
        t->next=q;
        free(rem);
    }
}

void lru(){
    int count,flag,fault;
    struct page *p;
    for(int i=0;i<n;i++){
        flag=0;count=0;
        if(head==NULL){
            fault=1;
            struct page *temp=(struct page*)malloc(sizeof(struct page));
            temp->i=i;
            temp->val=a[i];
            temp->next=NULL;
            head=temp;
            flag=1;
        }else{
            //check for page fault
            p=head;
            while(p!=NULL){
                if(p->val==a[i]){
                    flag=1;
                    p->i=i;
                    break;
                }
                p=p->next;
            }
        }
        //if fault occur
        struct page *temp=(struct page*)malloc(sizeof(struct page));
        temp->i=i;
        temp->val=a[i];
        temp->next=NULL;
        if(flag==0){
            fault++;
            //check if frame is full
            p=head;
            while(p->next!=NULL){
                p=p->next;
                count++;
            }
            if(count!=size-1)
                p->next=temp;
            else{
                //frame full
                remlru(temp);    
            }
        }
        printf("\n");
        p=head;
        while(p!=NULL){
            printf("%d-->",p->val);
            p=p->next;
        }
    }
    printf("\nNumber of faults = %d",fault);
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
    lru();
}
