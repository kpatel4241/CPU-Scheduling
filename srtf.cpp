#include<bits/stdc++.h>

using namespace std;

void SRTF(int bt[] , int at[] , int rt[] , int n)
{
  int waiting[10],turnaround[10],completion[10];
  int i,j,smallest,count=0,time;
  double avg=0,tt=0,end;

  bt[9]=INT_MAX;
  
  for(time=0;count!=n;time++)
  {
    smallest=9;
    for(i=0;i<n;i++)
    {
      if(at[i]<=time && bt[i]<bt[smallest] && bt[i]>0 )
      smallest=i;
    }
    bt[smallest]--;
  
    if(bt[smallest]==0)
    {
      count++;
      end=time+1;
      completion[smallest] = end;
      waiting[smallest] = end - at[smallest] - rt[smallest];
      turnaround[smallest] = end - at[smallest];
    }
  }

  cout<<"\n PID \tBurst Time \tArrival Time \tWaiting Time \tTurnaround Time \n";
  
  for(i=0;i<n;i++)
  {
    cout<<"P["<<i<<"]\t\t"<<rt[i]<<"\t\t"<<at[i]<<"\t\t"<<waiting[i]<<"\t\t"<<turnaround[i]<<endl;
    avg = avg + waiting[i];
    tt = tt + turnaround[i];
  }


  cout<<"\n Avg. waiting time = "<<(float)(avg/n)<<endl;
  cout<<"\n Avg. Turnaround Time = "<<(float)(tt/n)<<endl;
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
  
  SRTF(bt,at,rt,n);
   
  return 0;
}