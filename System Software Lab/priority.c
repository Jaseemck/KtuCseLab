#include<stdio.h>
struct process{
int ind,at,bt,pr,st,tt,wt;};

void sortpriority(struct process pc[],int n){
	int i,j;
	struct process temp;
    for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(pc[j].pr!=pc[j+1].pr){
				if(pc[j].pr<pc[j+1].pr){
					temp=pc[j];
					pc[j]=pc[j+1];
			pc[j+1]=temp;}}
			else{
				if(pc[j].at>pc[j+1].at){
					temp=pc[j];
					pc[j]=pc[j+1];
                     pc[j+1]=temp;
					 }
			    }
			}
		}
	}
				
 
 float waitingtime(struct process pc[],int n){
	 pc[0].st=0;
	 pc[0].wt=0;
     float twt=0.0;
     for(int i=1;i<n;i++){
		 pc[i].st=pc[i-1].st+pc[i-1].bt;
		 pc[i].wt=pc[i].st-pc[i].at;
	 twt+=pc[i].wt;}
	 twt=twt/n;
 }

float turnaroundtime(struct process pc[],int n){
float ttt=0.0;
for(int i=0;i<n;i++){
		 pc[i].tt=pc[i].wt+pc[i].bt;
		 ttt+=pc[i].tt;}
 ttt/=n;
 return ttt;}
 
 int main(){
	int n;
	printf("Enter no.of processses");
	scanf("%d",&n);
	struct process pc[n];
	printf("Enter arrival time, bursttime and priority\n");
	for(int i=0;i<n;i++){
		printf("p%d",i);
		pc[i].ind=i;
	scanf("%d,%d,%d",&pc[i].at,&pc[i].bt,&pc[i].pr);}
	sortpriority(pc,n);
	float avgwt,avgtt;
	avgwt=waitingtime(pc,n);
	avgtt=turnaroundtime(pc,n);
	printf("Process\twaitingtime\tturnaroundtime\n");
	for(int i=0;i<n;i++)
		printf("%pd\t\t%d\t\t%d\n",pc[i].ind,pc[i].wt,pc[i].tt);
	printf("Average waiting time : %f", avgwt);
    printf("\nAverage turnaround time : %f", avgtt);
 }
	
	
	
	
	
	
	
	
	