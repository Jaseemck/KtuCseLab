#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct dir{
    char dname[20];;
    struct dir *next;
    struct file{
        char fname[20];
        struct file *link;
    }*fhead;
}*dhead;

void display(){
    struct dir *p=dhead;
    while(p!=NULL){
        printf("\n%s\n",p->dname);
        struct file *q=p->fhead;
        while(q!=NULL){
            printf("  %s\n",q->fname);
            q=q->link;
        }
        p=p->next;
    }
}

/*..........................Add directory...............................*/

void adddir(char name[]){
    if(dhead==NULL){
        dhead=(struct dir*)malloc(sizeof(struct dir));
        strcpy(dhead->dname,name);
        dhead->next=NULL;
        dhead->fhead=NULL;
    }else{
        struct dir *temp=(struct dir*)malloc(sizeof(struct dir));
        strcpy(temp->dname,name);
        temp->next=NULL;
        temp->fhead=NULL;
        struct dir *p=dhead;
        while(p->next!=NULL)
            p=p->next;
        p->next=temp;
    }
}

/*........................Add file.................................*/

void addfile(char dn[], char fn[]){
    struct dir *p=dhead;
    int flag=0;
    while(p!=NULL){
        if(strcmp(p->dname,dn)==0){
            flag=1;
            struct file *temp=(struct file*)malloc(sizeof(struct file));
            strcpy(temp->fname,fn);
            temp->link=NULL;
            if(p->fhead==NULL){
                p->fhead=temp;
            }else{
                struct file *q=p->fhead;
                while(q->link!=NULL)
                    q=q->link;
                q->link=temp;
            }
            break;
        }
        p=p->next;
    }
    if(flag==0){
        printf("\nThe directory is not present... Insertion of file impossible\n");
    }
}

/*...........................Delete file...............................*/

void deletefile(char dn[],char fn[]){
    struct dir *p=dhead;
    while(p!=NULL){
        if(strcmp(p->dname,dn)==0){
            //directory present
            if(p->fhead==NULL){
                printf("\nNo files present in the directory\n");
                return;
            }
            if(strcmp(p->fhead->fname,fn)==0){
                //delete file head
                struct file *rem=p->fhead;
                p->fhead=p->fhead->link;
                free(rem);
                return;
            }
            //check if file is present
            struct file *q=p->fhead,*rem;
            while(q->link!=NULL){
                if(strcmp(q->link->fname,fn)==0){
                    //file present
                    rem=q->link;
                    q->link=rem->link;
                    free(rem);
                    return;
                }
                q=q->link;
            }
            printf("\nFile is not present .... deletion impossible\n");
            return;
        }
        p=p->next;
    }
    printf("\nThe directory is not possible .... deletion impossible\n");
}

/*...................................Search file.......................................*/

void searchfile(char dn[],char fn[]){
    struct dir *p=dhead;
    while(p!=NULL){
        if(strcmp(p->dname,dn)==0){
            //directory present
            if(p->fhead==NULL){
                printf("\nNo files present in the directory\n");
                return;
            }
            if(strcmp(p->fhead->fname,fn)==0){
                //delete file head
                printf("\nFile present\n");
                return;
            }
            //check if file is present
            struct file *q=p->fhead,*rem;
            while(q->link!=NULL){
                if(strcmp(q->link->fname,fn)==0){
                    //file present
                    printf("\nFile present\n");
                    return;
                }
                q=q->link;
            }
            printf("\nFile is not present .... deletion impossible\n");
            return;   
        }
        p=p->next;
    }
    printf("\nThe directory is not possible .... deletion impossible\n");
}

void main(){
    int op;
    char d[20],f[20];
    dhead=NULL;
    while(1){
        printf("\n\nSelect operation:\n");
        printf("1.Add directory\n2.Add file\n3.Delete file\n4.Search file\n5.Traverse\n6.Exit\n");
        printf("Enter your option: ");
        scanf("%d",&op);
        switch(op){
            case 1: printf("\nEnter the directory name: ");
                    scanf("%s",&d);
                    adddir(d);
                    break;
            case 2: printf("\nEnter the directory name: ");
                    scanf("%s",&d);
                    printf("\nEnter the file name: ");
                    scanf("%s",&f);
                    addfile(d,f);
                    break;
            case 3: printf("\nEnter the directory name: ");
                    scanf("%s",&d);
                    printf("\nEnter the file name: ");
                    scanf("%s",&f);
                    deletefile(d,f);
                    break;
            case 4: printf("\nEnter the directory name: ");
                    scanf("%s",&d);
                    printf("\nEnter the file name: ");
                    scanf("%s",&f);
                    searchfile(d,f);
                    break;
            case 5: display();
                    break;
            case 6:exit(0);
        }
    }
}
