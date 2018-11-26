#include<stdio.h>

int a[20];

void fcfs(int l){
    int i,diff,seek=0;
    float avg;
    for(i=1;i<=l-2;i++){
        if(a[i]>a[i+1])
           diff=a[i]-a[i+1];
        else
           diff=a[i+1]-a[i];
        printf("\nSeek length from %d to %d = %d",a[i],a[i+1],diff);
        seek+=diff;
    }
    avg=(float)seek/(l-2);
    printf("\nAverage seek length = %f",avg);
}

int sort(int head, int l){
    int i,j,temp,pos;
    for(i=0;i<l;i++){
        for(j=0;j<l-i-1;j++){
            if(a[j+1]<a[j]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(i=1;i<l-1;i++){
        if(a[i]==head){
            pos=i;
            break;
        }
    }
    return pos;
}

void scan(int head, int pos, int l){
    int i,seek=0,diff;
    float avg;
    for(i=pos;i>0;i--){
        diff=a[i]-a[i-1];
        printf("\nSeek length from %d to %d = %d",a[i],a[i-1],diff);
        seek+=diff;
    }
    printf("\nSeek length from %d to %d = %d",0,a[pos+1],a[pos+1]);
    seek+=a[pos+1];
    for(i=pos+1;i<l;i++){
        diff=a[i+1]-a[i];
        printf("\nSeek length from %d to %d = %d",a[i],a[i+1],diff);
        seek+=diff;
    }
    avg=(float)seek/(l-2);
    printf("\nAverage seek length = %f",avg);
    
}

void cscan(int head, int pos, int l){
    int seek=0;
    int i,diff;
    float avg;
    for(i=pos;i>0;i--){
       diff=a[i]-a[i-1];
       printf("\nSeek length from %d to %d = %d",a[i],a[i-1],diff);
       seek+=diff;
       }
    for(i=l;i>pos+1;i--){
       diff=a[i]-a[i-1];
       printf("\nSeek lenth from %d to %d = %d",a[i],a[i-1],diff);
       seek+=diff;      
    }
    avg=(float)seek/(l-2);
    printf("\nAverage seek length = %f",avg);
}

void main(){
    int i,j,n,head,last,l,p;
    printf("\nEnter the number of requests");
    scanf("%d",&n);
    printf("Enter the requests:\n");
    for(i=2;i<=n+1;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the head position");
    scanf("%d",&head);
    printf("enter the last track position of disk");
    scanf("%d",&last);
    l=n+2;
    a[0]=0;
    a[1]=head;
    a[l]=last;
    printf("\n\nFCFS: ");
    fcfs(l);
    p=sort(head,l);
    printf("\n\nSCAN: ");
    scan(head,p,l);
    printf("\n\nCSCAN: ");
    cscan(head,p,l);
}
