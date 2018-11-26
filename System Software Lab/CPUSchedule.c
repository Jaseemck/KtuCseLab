#include<stdio.h>

int burst[20],arrival[20];

void fcfs(int n){
	int i,sumw=0,sumt=0;
	double avgw,avgt;
	int wait[20],turn[20];
	
	wait[0]=0;
	for(i=0;i<n;i++){
		wait[i+1]=wait[i]+burst[i];
	}
	//waiting time and turnaround time
	for(i=0;i<n;i++){
		wait[i]=wait[i]-arrival[i];
		sumw+=wait[i];
		turn[i]=wait[i]+burst[i];
		sumt+=turn[i];
	}
	avgw=sumw/n;
	avgt=sumt/n;
	printf("\nProcess\tArrivalTime\tBurstTime\tWaitingTime\tTurnaroundTime");
	for(i=0;i<n;i++){
		printf("\n%d\t%d\t\t%d\t\t%d\t\t%d",i+1,arrival[i],burst[i],wait[i],turn[i]);
	}
	printf("\n\nAverage waiting time = %f",avgw);
	printf("\nAverage turnaround time = %f",avgt);
}


void sjf(int n,int p[]){
	int i,j,pos,temp,sumw=0,sumt=0;
	double avgw,avgt;
	int wait[20],turn[20];
	for(i=0;i<n;i++){
		pos=i;
		for(j=i+1;j<n;j++){
			if(burst[j]<burst[pos]){
				pos=j;	
			}
		}
		temp=burst[i];
		burst[i]=burst[pos];
		burst[pos]=temp;
		
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;
	}
	//waiting time and turnaround time
	for(i=0;i<n;i++){
		wait[i]=0;
		for(j=0;j<i;j++){
			wait[i]+=burst[j];
		}
		sumw+=wait[i];
		turn[i]=wait[i]+burst[i];
		sumt+=turn[i];
	}
	avgw=sumw/n;
	avgt=sumt/n;
	printf("\nProcess\tBurstTime\tWaitingTime\tTurnaroundTime");
	for(i=0;i<n;i++){
		printf("\n%d\t%d\t\t%d\t\t%d",p[i],burst[i],wait[i],turn[i]);
	}
	printf("\n\nAverage waiting time = %f",avgw);
	printf("\nAverage turnaround time = %f",avgt);
}

void round_robin(int n, int temp[], int tq){
   int limit,i=0;
   limit=n;
   while(limit!=0){
      if(temp[i]<tq && temp[i]>0){
          total+=temp[i];
          temp[i]=0;
          counter=1;
      }else if{
          total+=tq;
          temp[i]-=tq;
      }
   }
}


void main(){
	int n,i;
	int p[20],pr[20],temp[20];
	printf("Enter the number of process: ");
	scanf("%d",&n);
	printf("Enter the burst time for:\n");
	for(i=0;i<n;i++){
		printf("Process %d: ",i+1);
		scanf("%d",&burst[i]);
		p[i]=i+1;
		temp[i]=burst[i];
	}
	printf("Enter the arrival time for:\n");
	for(i=0;i<n;i++){
		printf("Process %d: ",i+1);
		scanf("%d",&arrival[i]);
	}
	printf("Enter the priority for:\n");
	for(i=0;i<n;i++){
		printf("Process %d: ",i+1);
		scanf("%d",&pr[i]);
	}
	fcfs(n);
	sjf(n,p);
	round_robin(n,temp,tq)
}
