#include<stdio.h>

int main()
{
 int total_frames, total_pages, hit = 0;
 int rf[25], pf[10], arr[25], time[25];
 int m, n, page, flag, k, minimum_time, temp;
 printf("Enter Total Number of elements in reference string:\t");
 scanf("%d", &total_pages);
 printf("Enter Total Number of Frames:\t");
 scanf("%d", &total_frames);
 for(m = 0; m < total_frames; m++)
 {
 pf[m] = -1;
 }
 for(m = 0; m < 25; m++)
 {
 arr[m] = 0;
 }
 printf("Enter Values of Reference String\n");
 for(m = 0; m < total_pages; m++)
 {
 printf("Enter Value No.[%d]:\t", m + 1);
 scanf("%d", &rf[m]);
 }
 printf("\n");
 for(m = 0; m < total_pages; m++)
 {
 arr[rf[m]]++;
 time[rf[m]] = m;
 flag = 1;
 k = pf[0];
 for(n = 0; n < total_frames; n++)
 {
 if(pf[n] == -1 || pf[n] == rf[m])
 {
 if(pf[n] != -1)
 {
 hit++;
 }
 flag = 0;
 pf[n] = rf[m];
 break;
 }
 if(arr[k] > arr[pf[n]])
 {
 k = pf[n];
 }
 }
 if(flag)
 {
 minimum_time = 25;
 for(n = 0; n < total_frames; n++)
 {
 if(arr[pf[n]] == arr[k] && time[pf[n]] < minimum_time)
 {
 temp = n;
 minimum_time = time[pf[n]];
 }
 }
 arr[pf[temp]] = 0;
 pf[temp] = rf[m];
 }
 for(n = 0; n < total_frames; n++)
 {
 printf("%d\t", pf[n]);
 }
 printf("\n");
 }
 printf("Page Faults:\t%d\n", total_pages-hit);
 return 0;
}
