#include<bits/stdc++.h>
using namespace std;

struct Process{
   int pname;
   int bt;
   int priority;
};

bool compare(Process a, Process b){
   return (a.priority > b.priority);
}
void waitingtime(Process pro[], int n, int wt[]){
   wt[0] = 0;
   for (int i=1;i<n;i++)
      wt[i] = pro[i-1].bt + wt[i-1] ;
}

void turnarround( Process pro[], int n, int wt[], int tat[]){
   for (int i=0;i<n;i++)
      tat[i] = pro[i].bt + wt[i];
}

void scheduling(Process pro[], int n){
    sort(pro, pro + n, compare);
   int wt[n], tat[n], total_wt = 0, total_tat = 0;
   waitingtime(pro, n, wt);
   turnarround(pro, n, wt, tat);
   cout << "Processes "<< " Burst time " << " Waiting time " << " Turn around time\n";
   for (int i=0;i<n;i++) {
      total_wt = total_wt + wt[i];
      total_tat = total_tat + tat[i];
      cout << " " << pro[i].pname << "\t\t" << pro[i].bt << "\t " << wt[i] << "\t\t " << tat[i] <<endl;
   }
   cout << "\nAverage waiting time = " << (float)total_wt / (float)n;
   cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}

int main(){
   Process pro[] = {{1,8,1},{2,7,0},{3,5,2},{4,5,3}};
   int n = sizeof pro / sizeof pro[0];
   scheduling(pro, n);
   return 0;
}
