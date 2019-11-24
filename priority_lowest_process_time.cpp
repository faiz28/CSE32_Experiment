#include<bits/stdc++.h>
using namespace std;
struct SJF{
    int Pro_ID,Bu_Ti,priority;
};

bool cmp(SJF a,SJF b)
{
    if(a.priority!=b.priority) return a.priority>b.priority;

    return a.Bu_Ti<b.Bu_Ti;
}
int main()
{

    int pro_n,total_tu=0,total_wa=0;
    cout<<"Take input number of process: ";
    cin>>pro_n;

    SJF process[pro_n+5];
    cout<<"Process_ID\t Burst_Time\t Priority\n";
    for(int i=1;i<=pro_n;i++)
    {
        cin>>process[i].Pro_ID>>process[i].Bu_Ti>>process[i].priority;
    }
    sort(process+1,process+(pro_n+1),cmp);

    int Tu_ti[pro_n+5],Wa_ti[pro_n+5];
    Tu_ti[0]=0;
    for(int i=1;i<=pro_n;i++)
    {
        Tu_ti[i]=Tu_ti[i-1]+process[i].Bu_Ti;
        Wa_ti[i]=Tu_ti[i]-process[i].Bu_Ti;
        total_tu+=Tu_ti[i];
        total_wa+=Wa_ti[i];
    }
    cout<<"Process_ID\tBurst_Time\tPriority\tWating_Time\tTurn_Around_Time\n";
    for(int i=1;i<=pro_n;i++)
    {
        cout<<process[i].Pro_ID<<"\t\t"<<process[i].Bu_Ti<<"\t\t"<<process[i].priority<<"\t\t"<<Wa_ti[i]<<"\t\t"<<Tu_ti[i]<<endl;
    }
    cout<<"average waiting time "<< (float)total_wa/(float)pro_n<<endl;
    cout<<"Average turn around time "<<(float)total_tu/(float)pro_n<<endl;



}
