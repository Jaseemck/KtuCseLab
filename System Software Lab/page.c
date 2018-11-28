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

/*........................First Come First Serve........................*/

void fcfs(){
    int i,flag,fault=0,count;
    struct page *p,*q;
    for(i=0;i<n;i++){
        flag=0;
        if(head==NULL){
            fault++;
            struct page *temp=(struct page*)malloc(sizeof(struct page));
            temp->val=a[i];
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
            p=head;
            while(p->next!=NULL){
                count++;
                p=p->next;
            }
            if(count!=size-1){
                p->next=temp;
            }else{
                p->next=temp;
                q=head;
                head=head->next;
                free(q);
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

/*........................End of First Come First Serve........................*/



/*........................Least Recently Used........................*/

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
            flag=ishit(a[i],i);
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
    printf("\nNumber of faults = %d\n",fault);
}

/*........................End of Least Recently Used........................*/





/*........................Least Frequently Used........................*/

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

/*........................End of Least Frequently Used........................*/



void main(){
    int i;
    head=NULL;
    printf("\nEnter the number of pages: ");
    scanf("%d",&n);
    printf("\nEnter the frame size: ");
    scanf("%d",&size);
    printf("\nEnter the pages: \n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\nFirst Come First Serve\n");
    fcfs();
    head=NULL;
    printf("\nLeast Recently Used\n");
    lru();
    head=NULL;
    printf("\nLeast Frequently Used\n");
    lfu();
    
}
