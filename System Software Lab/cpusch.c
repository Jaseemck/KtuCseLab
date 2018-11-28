#include<stdio.h>

struct cpusch{
    int pid;
    int burst,arrival,priority,t;
    int wait,response,turn;
    int processed;
};

struct cpusch s[20];

//To accept data

int getdata(){
    int n,i;
    printf("\nEnter the number of process: ");
    scanf("%d",&n);
    printf("\nEnter process parameters:\n");
    for(i=0;i<n;i++){
        printf("\nProcess %d: ",i+1);
        printf("\nBurst Time: ");
        scanf("%d",&s[i].burst);
        s[i].t=s[i].burst;
        printf("Arrival Time: ");
        scanf("%d",&s[i].arrival);
        printf("Priority: ");
        scanf("%d",&s[i].priority);
        s[i].pid=i+1;
    }
    return n;
}

//Display data
void displaydata(int n){
    int i;
    printf("\nProcess details: ");
    printf("\n\n............................");
    printf("\n\nProcess   Priority   BT   AT   WT   TT");    
    for(i=0;i<n;i++){
    	printf("\n%d         %d          %d    %d    %d    %d",s[i].pid,s[i].priority,s[i].burst,s[i].arrival,s[i].wait,s[i].turn);
    }
}

void fcfs(int n){
    struct cpusch temp;
    double avgw,avgt;
    int i,j,sumw=0,sumt=0;
    for(i=0;i<n-1;i++){
      for(j=0;j<n-i-1;j++){
          if(s[j+1].arrival < s[j].arrival){
              temp=s[j];
              s[j]=s[j+1];
              s[j+1]=temp;
          }
      }
    }
    s[0].wait=0;
    for(i=0;i<n-1;i++){
        s[i+1].wait=s[i].wait+s[i].burst;
    }
    for(i=0;i<n;i++){
        s[i].wait-=s[i].arrival;
        s[i].turn=s[i].wait+s[i].burst;
        sumw+=s[i].wait;
        sumt+=s[i].turn;
    }
    avgw=(double)sumw/n;
    avgt=(double)sumt/n;
    displaydata(n);
    printf("\n\nAverage waiting time = %f",avgw);
    printf("\nAverage turnaround time = %f",avgt);
}

void sjfs(int n){
    struct cpusch temp;
    double avgw,avgt;
    int i,j,time=0,pos,sumw=0,sumt=0;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(s[j+1].burst < s[j].burst){
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
        s[i].processed=0;
    }
    
    for(i=0;i<n;i++){
        if(s[i].processed==0){
            pos=i;
            if(time<s[i].arrival){
                for(j=i+1;j<n;j++){
                    if(s[j].arrival<=time){
                        pos=j;
                        i--;
                        break;
                    }
                }
            }
            s[pos].processed=1;
            s[pos].wait=time-s[pos].arrival;
            s[pos].turn=s[pos].wait+s[pos].burst;
            time+=s[pos].burst;
            sumw+=s[pos].wait;
            sumt+=s[pos].turn;
        }
    }
    displaydata(n);
    avgw=(double)sumw/n;
    avgt=(double)sumt/n;
    printf("\nAverage waiting time = %f",avgw);
    printf("\nAverage turnaround time = %f",avgt);    
}

void round_robin(int n,int tq){
    int total=0,counter=0;
    int i,j,limit,sumw=0,sumt=0;
    float avgw,avgt;
    struct cpusch temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(s[j+1].arrival < s[j].arrival){
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    printf("\nProcess details: ");
    printf("\n\nProcess   Priority  BT   AT   WT   TT");    
    
    for(i=0,limit=n;limit!=0;){
        if((s[i].t<=tq)&&(s[i].t>0)){
           total=total+s[i].t;
           s[i].t=0;
           counter=1;
        }
        else if(s[i].t>0){
           total=total+tq;
           s[i].t=s[i].t-tq;       
        }
        if((s[i].t==0)&&(counter==1)){
            counter=0;
            limit--;
            s[i].wait=total-s[i].burst-s[i].arrival;
            s[i].turn=s[i].wait+s[i].burst;
            printf("\n%d         %d          %d    %d    %d   %d",s[i].pid,s[i].priority,s[i].burst,s[i].arrival,s[i].wait,s[i].turn);
            sumw+=s[i].wait;
            sumt+=s[i].turn;
        }
        if(i==n-1)
            i=0;
        else
            i++;
    }
    avgw=(double)sumw/n;
    avgt=(double)sumt/n;
    printf("\nAverage waiting time = %f",avgw);
    printf("\nAverage turnaround time = %f",avgt);
}

void priority(int n){
    struct cpusch temp;
    float avgw,avgt;
    int i,j,time=0,pos,sumw=0,sumt=0;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(s[j+1].priority < s[j].priority){
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    s[0].wait=0;
    for(i=0;i<n-1;i++){
        s[i+1].wait=s[i].wait+s[i].burst;
    }
    for(i=0;i<n;i++){
        s[i].turn=s[i].wait+s[i].burst;
        sumw+=s[i].wait;
        sumt+=s[i].turn;
    }
    printf("\n\nProcess   Priority   BT   WT   TT");    
    for(i=0;i<n;i++){
    	printf("\n%d         %d          %d    %d    %d",s[i].pid,s[i].priority,s[i].burst,s[i].wait,s[i].turn);
    }
    avgw=(double)sumw/n;
    avgt=(double)sumt/n;
    printf("\nAverage waiting time = %f",avgw);
    printf("\nAverage turnaround time = %f",avgt);    
}

void main(){
    int n,tq;
    n=getdata();
    printf("\nFCFS:");
    fcfs(n);
    printf("\n.............................................");
    printf("\nSJFS:");
    sjfs(n);
    printf("\nEnter the time quantum: ");
    scanf("%d",&tq);
    printf("\n.............................................");
    printf("\nROUND ROBIN:");
    round_robin(n,tq);
    printf("\n.............................................");
    printf("\nPRIORITY:");
    priority(n);
}
