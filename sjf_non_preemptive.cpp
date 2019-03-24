#include<bits/stdc++.h>

using namespace std;

struct Process
{
    int pid;
    int bt;
};


bool _max_(Process A ,Process B)
{
    return(A.bt > B.bt);
}



void wait_time(Process proc[] , int n , int wt[])
{
    wt[0] = 0;
    for(int i=1;i<n;i++)
        wt[i] = proc[i-1].bt + wt[i-1];
}


void turn_around_time(Process proc[] , int n, int wt[] , int tat[])
{
    for(int i=0;i<n;i++)
        tat[i] = proc[i].bt + wt[i];
}

void avg_time(Process proc[] , int n )
{
    int wt[n],tat[n], total_wt = 0 , total_tat = 0;

    wait_time(proc,n,wt);

    turn_around_time(proc ,n , wt , tat);

    cout<<"\n Process \tBurst Time \tWaiting Time \tTurn Around Time\n";

    for(int i=0;i<n;i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];

        cout<<" "<<proc[i].pid<<"\t\t"<<proc[i].bt<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    }

    cout<<"\n Avg Waiting Time = "<<(float)(total_wt/n)<<endl;
    cout<<"\n Avg. Turn Around Time = "<<(float)(total_tat/n)<<endl;

}


int main()
{
    Process proc[] = {{0,60} , {1,25} , {2,18}};
    int n = sizeof(proc)/sizeof(proc[0]);

    sort(proc,proc+n,_max_);

    avg_time(proc,n);

    return 0;
}
