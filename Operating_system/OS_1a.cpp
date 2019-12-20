#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("file.txt","r",stdin);
    int pro_n;
    cout<<"Take input number of process: ";
    cin>>pro_n;

     string Pro_ID[pro_n+5];
     float Bu_Ti[pro_n+5],Wa_ti[pro_n+5],Tu_ti[pro_n+5],Arri_Ti[pro_n+5],total_tu=0,total_wa=0;


    cout<<"ProcessID\t ArrivalTime\t BurstTime\n";
    Tu_ti[0]=0;

    for(int i=1;i<=pro_n;i++)
    {
        cin>>Pro_ID[i]>>Arri_Ti[i]>>Bu_Ti[i];

        Tu_ti[i]=Tu_ti[i-1]+Bu_Ti[i];
        Wa_ti[i]=Tu_ti[i]-Bu_Ti[i];
        total_tu+=Tu_ti[i];
        total_wa+=Wa_ti[i];
    }

    cout<<"ProcessID\tArrivalTime\tBurstTime\tWatingTime\tTurnaroundTime\n";
    for(int i=1;i<=pro_n;i++)
    {
        cout<<Pro_ID[i]<<"\t\t"<<Arri_Ti[i]<<"\t\t"<<Bu_Ti[i]<<"\t\t"<<Wa_ti[i]<<"\t\t"<<Tu_ti[i]<<endl;
    }
    cout<<"average waiting time "<< (float)total_wa/(float)pro_n<<endl;
    cout<<"Average turnaround time "<<(float)total_tu/(float)pro_n<<endl;



}