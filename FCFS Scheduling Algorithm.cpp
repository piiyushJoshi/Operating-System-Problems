#include <stdio.h>

void findWaitingTime(int processes[],int n,int bt[ ],int wt[]){
    wt[0] = 0;
    for(int i=1;i<n;i++)  
        wt[i] = bt[i-1] + wt[i-1];  
}  

void findTurnAroundTime(int processes[],int n,int bt[],int wt[],int tat[]){
    for(int i=0;i<n;i++)  
        tat[i] = bt[i] + wt[i];  
}  

int main(){ 
    int processes[] = {1,2,3,4,5};  
    int n = sizeof processes / sizeof processes[0];
    int burst_time[] = {9,7,8,11,9};  
  
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 
    findWaitingTime(processes, n, burst_time, wt);
    findTurnAroundTime(processes, n, burst_time, wt, tat);
    printf("Processes\tBurst time\tWaiting time\tTurn around time\n");  
    for (int i=0;i<n;i++){
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("%d", (i + 1));
        printf("\t\t%d", burst_time[i]);
        printf("\t\t%d", wt[i]);
        printf("\t\t%d\n", tat[i]);
    }
    return 0;  
}  
