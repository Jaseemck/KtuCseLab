#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct file{
    char fname[20];
    struct file *link;
}*fhead;

void sinsert(){
    char str[20];
    printf("\nEnter the file name: ");
    scanf("%s",&str);
    struct file *temp=(struct file*)malloc(sizeof(struct file));
    strcpy(temp->fname,str);
    temp->link=NULL;
    if(fhead==NULL){
        fhead=temp;
    }else{
        struct file *p=fhead;
        while(p->link!=NULL)
            p=p->link;
        p->link=temp;
    }
}

void sdelete(){
    int flag=0;
    char str[20];
    printf("\nEnter the file name to be deleted: ");
    scanf("%s",&str);
    if(strcmp(fhead->fname,str)==0){
        struct file *p=fhead;
        fhead=fhead->link;
        free(p);
    }else{
        struct file *p=fhead;
        while(p->link!=NULL){
            if(strcmp(p->link->fname,str)==0){
                struct file *temp=p->link;
                p->link=temp->link;
                free(temp);
                flag=1;
                printf("%s is deleted",str);
            }
            p=p->link;
        }
        if(flag==0)
            printf("\nFile not found");
    }
}

void ssearch(){
    char str[20];
    int flag=0;
    printf("\nEnter the file name to be searched: ");
    scanf("%s",&str);
    struct file *p=fhead;
    while(p!=NULL){
        if(strcmp(p->fname,str)==0){
            printf("\nFile is present");
            flag=1;break;
        }
        p=p->link;
    }
    if(flag==0)
        printf("\nFile not found");
}

void sdisplay(char dname[20]){
    printf("\nDirectory: %s\n",dname);
    struct file *p=fhead;
    while(p!=NULL){
        printf("%s-->",p->fname);
        p=p->link;
    }
}

void main(){
    char dname[20];
    int op,ch;
    fhead=NULL;
    printf("\nEnter the directory name: ");
    scanf("%s",&dname);
    while(1){
        printf("\n1.Insert File\n2.Delete File\n3.Search File\n4.Display Files\n5.Exit");
        printf("\nEnter your option: ");
        scanf("%d",&op);
        switch(op){
            case 1: sinsert();break;
            case 2: sdelete();break;
            case 3: ssearch();break;
            case 4: sdisplay(dname);break;
            case 5: exit(0);
            default: printf("\nInvalid option");
        }
    }
}
