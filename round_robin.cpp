#include<bits/stdc++.h>

using namespace std;


void round_robin(int bt[] , int at[] , int rt[] , int n)
{
  int count,time,remain,flag=0,time_quantum=5; 
  int wait_time=0,turnaround_time=0;

  remain=n; 

  cout<<"\nProcess \tTurnaround Time Waiting Time\n\n";

  for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      
      cout<<"P["<<count<<"]"<<"\t\t"<<time-at[count]<<"\t\t"<<time-at[count]-bt[count]<<endl;
      
      wait_time+=time-at[count]-bt[count]; 
      turnaround_time+=time-at[count]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 
  }

  cout<<"\n Avg. Wait Time = "<<(float)(wait_time*1.0/n)<<endl;

  cout<<"\n Avg. Turnaround Time = "<<(float)(turnaround_time*1.0/n)<<endl;

} 
 


int main() 
{ 
 
  int count=0;

  int at[] = {0,2,3};
  int bt[] = {60,18,25};

  int n = sizeof(bt)/sizeof(bt[0]);

  int rt[n];
  
  for(count=0;count<n;count++) 
  { 
    rt[count]=bt[count]; 
  } 
  
  round_robin(bt,at,rt,n);
  
  return 0; 
}
