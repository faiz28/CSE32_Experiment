#include<bits/stdc++.h>
using namespace std;

vector<vector<int> >vc;
void findTime(int processes[],int n,int burst_time[],int quantum)
{
    int rem[n+5],cnt=0,st_tm[n+5],check[n+5];

    for(int i=0;i<n;i++ ) {rem[i]=burst_time[i];check[i]=0;}

    int i=0;
    while(true)
    {

        for(int i=0;i<n;i++)
        {

            if(rem[i]>0){
                if(rem[i]>=quantum) rem[i]-=quantum;
                else rem[i]=0;
            }
            else{
                if(check[i]==0)
                {
                    check[i]=1;
                    cout<<i<<endl;
                    vc[cnt].push_back(processes[i]);
                    vc[cnt].push_back(burst_time[i]);
                    cnt++;
                }
            }

        }
        if(cnt==2)break;

    }

    cout<<"process_id\t burst_time\n";
    for(int i=0;i<n;i++)
    {
        cout<<vc[i][0]<<" "<<vc[i][1]<<endl;
    }
}
int main()
{
    freopen("input.txt","r",stdin);
	int pro_n,total_tu=0,total_wa=0;
    //cout<<"Take input number of process: ";
    cin>>pro_n;

    int processes[pro_n+5],burst_time[pro_n+5];
    //cout<<"Process_ID\tburst_time\n";
    for(int i=0;i<pro_n;i++)
    {
        cin>>processes[i]>>burst_time[i];
    }
	int quantum = 4;
	findTime(processes, pro_n, burst_time, quantum);



	return 0;
}
