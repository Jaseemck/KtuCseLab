
#include<stdio.h>
int main(){
 int pno;
 printf("Enter number of processes\n");
 scanf("%d",&pno);
 int bt[pno];int at[pno];
int i,j;
for(i=0;i<pno;i++)
{
 printf("Enter arrival and burst time for P%d ",i);
 scanf("%d%d",&at[i],&bt[i]);
}
 int wt[pno];
 int st[pno];
 int tt[pno];
 float avgwt;
 float avgtt;
int ct;ct=0;
 avgwt=0.0;
 for(i=0;i<pno;i++){
 ct=0;
 for(j=0;j<i;j++)
 {
 ct+=bt[j];
 }
 st[i]=ct;
 }
printf("Equations used:\n Waiting time = Service Time - Arrival Time \n Turnaround time = Wait time + Execution time\n ");
 for(i=0;i<pno;i++)
{
 wt[i]=st[i]-at[i];
 tt[i]=wt[i]+bt[i];
 avgwt+=wt[i];
 avgtt+=tt[i];
}avgwt/=pno;
avgtt/=pno;
 printf("Process\tWaiting time\tTurnaround time\n");
 for(i=0;i<pno;i++){
 printf("P%d\t\t%d\t\t%d\n",i,wt[i],tt[i]);
 }
 printf("Average waiting time is %f \n",avgwt);
 printf("Average turnaround time is %f \n",avgtt);
}
