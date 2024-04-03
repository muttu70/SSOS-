#include<stdio.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
 int main()
 {
     int bt[20],p[20],n,i,j;
     printf("Enter number of process:");
     scanf("%d",&n);
     printf("\nEnter Burst Time:\n");
     for(i=0;i<n;i++)
     {
         printf("p%d:",i+1);
         scanf("%d",&bt[i]);
         p[i]=i+1;
     }
     //sorting of burst times
     for(i=0;i<n;i++)
     {
         for(j=i+1;j<n;j++)
         {
             if(bt[j]<bt[i]){
                swap(&bt[i], &bt[j]);
                swap(&p[i], &p[j]);
             }
         }
     }
     int tat = 0,wt = 0;
     float total_wait = 0;
     printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time");
     for(i=0;i<n;i++)
     {
         tat = bt[i] + wt;
         printf("\np%d\t\t %d\t\t %d\t\t\t%d",p[i],bt[i],wt,tat);
         total_wait += wt;
         wt = tat;
     }
     printf("\n\nAverage Waiting Time=%f",(total_wait)/n);
     printf("\nAverage Turnaround Time=%f",(total_wait+tat)/n);
 }
