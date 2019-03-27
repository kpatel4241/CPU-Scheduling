//
// Created by KP on 23-03-2019.
//
#include<bits/stdc++.h>
using namespace std;


bool _max_(int bt_a ,int bt_b)
{
    return(bt_a < bt_b);
}

void wait_time(int processes[], int n, int bt[], int wt[], int at[])
{
    int service_time[n];
    service_time[0] = 0;
    wt[0] = 0;

    for (int i = 1; i < n ; i++)
    {
        service_time[i] = service_time[i-1] + bt[i-1];

        wt[i] = service_time[i] - at[i];

        if (wt[i] < 0)
            wt[i] = 0;
    }
}


void turn_around_time(int processes[], int n, int bt[],
                     int wt[], int tat[])
{
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}


void avg_time(int processes[], int n, int bt[], int at[])
{
    int wt[n], tat[n] ;
    float pr[n];

    wait_time(processes, n, bt, wt, at);

    turn_around_time(processes, n, bt, wt, tat);

    cout << "Processes " << " Burst Time " << " Arrival Time " << " Waiting Time " << " Turn-Around Time " << " Completion Time "<<" Penalty ratio \n";

    int total_wt = 0, total_tat = 0;
    for (int i = 0 ; i < n ; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        int compl_time = tat[i] + at[i];
        pr[i] = (float)tat[i]/(float)bt[i];
        cout << "P[" << i <<"]"<< "\t\t" << bt[i] << "\t\t" << at[i] << "\t\t" << wt[i] << "\t\t "<< tat[i]  <<  "\t\t " << compl_time <<"\t\t"<< pr[i]<< endl;
    }

    cout << "Average waiting time = " << (float)total_wt / (float)n<<endl;
    cout << "\nAverage turn around time = " << (float)total_tat / (float)n<<endl;
}

/*
// Reading the input values from the file.
int main()
{
    int processes[] = {0, 1, 2};
    int n = sizeof(processes)/ sizeof(processes[0]);
    int burst_size = 0 , arrival_size = 0;

    int burst_time[100] , arrival_time[100];

    ifstream burst_fin("C:\\Users\\KP\\CLionProjects\\CPU Scheduling\\burst.txt",ios::in);
    if (burst_fin.is_open())
    {
        while ( true)
        {
            int x1;
            burst_fin >> x1;
            if (burst_fin.eof())
                break;
            burst_time[burst_size++] = x1;
        }
        burst_fin.close();
    }


    ifstream arrival_fin("C:\\Users\\KP\\CLionProjects\\CPU Scheduling\\arrival_time.txt",ios::in);
    if (arrival_fin.is_open())
    {
        while ( true)
        {
            int x2;
            arrival_fin >> x2;
            if (arrival_fin.eof())
                break;
            arrival_time[arrival_size++] = x2;
        }
        arrival_fin.close();
    }

    avg_time(processes, n, burst_time, arrival_time);

    return 0;
}
*/

// providing the static input values.
int main()
{
    int pid[] = {0,1,2};
    int at[] = {0,2,3};
    int bt[] = {60,18,25};
    int n = sizeof(pid)/sizeof(pid[0]);

    sort(bt,bt+n,_max_);

    avg_time(pid,n,bt,at);

    return 0;
}
