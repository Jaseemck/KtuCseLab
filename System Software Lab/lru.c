#include<stdio.h>
int main(){
 int frames;
 printf("Enter number of frames\n");
 scanf("%d",&frames);
 int rf[100];
 printf("Enter the reference string max size 20 end with -1\n");
 int i;
 int ele;
 ele=0;
 int lg;
 lg=0;
 for(i=0;i<20;i++){
 scanf("%d",&ele);
 rf[i]=ele;
 if(ele==-1)
 break;
 lg++;
 }
 int pf[frames];
 int miss;
 for(i=0;i<frames;i++)
 pf[i]=-1;
 int pos=0;
 int rp;
 int k;k=0;
 int h;h=0;
 miss=lg;
 while(rf[k]!=-1){
 for(i=0;i<frames;i++){
 if(rf[k]==pf[i])
 h=1;
 }
 if(h==0){
 if(pos<frames){
 pf[pos]=rf[k];
 pos++;
 }
 else{
 rp=rf[k-frames];
 for(i=0;i<frames;i++){
 if(pf[i]==rp)
 pf[i]=rf[k];
 }
 }
 }
 else
 {
 miss--;
 }

 k++;
 h=0;
 printf("\nStack now\n");
 for(i=0;i<frames;i++){
 printf("%d \t",pf[i]);
 }
 }
}
