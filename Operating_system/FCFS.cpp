#include<bits/stdc++.h>
using namespace std;

int main()
{

    int pro_n,total_tu=0,total_wa=0;
    cout<<"Take input number of process: ";
    cin>>pro_n;

    int Pro_ID[pro_n+5],Bu_Ti[pro_n+5],Wa_ti[pro_n+5],Tu_ti[pro_n+5];


    cout<<"Process_ID\t Burst_Time\n";
    Tu_ti[0]=0;

    for(int i=1;i<=pro_n;i++)
    {
        cin>>Pro_ID[i]>>Bu_Ti[i];

        Tu_ti[i]=Tu_ti[i-1]+Bu_Ti[i];
        Wa_ti[i]=Tu_ti[i]-Bu_Ti[i];
        total_tu+=Tu_ti[i];
        total_wa+=Wa_ti[i];
    }

    cout<<"Process_ID Burst_Time Wating_Time Turn_Around_Time\n";
    for(int i=1;i<=pro_n;i++)
    {
        cout<<Pro_ID[i]<<"\t\t"<<Bu_Ti[i]<<"\t\t"<<Wa_ti[i]<<"\t\t"<<Tu_ti[i]<<endl;
    }
    cout<<"average waiting time "<< (float)total_wa/(float)pro_n<<endl;
    cout<<"Average turn around time "<<(float)total_tu/(float)pro_n<<endl;



}
