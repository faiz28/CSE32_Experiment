#include<bits/stdc++.h>
using namespace std;
struct process{
    string pid;
    int arrival,burst,priority,wating;
};

bool comp(process a,process b)
{
     return a.priority>b.priority;
}
void addP(int num){
    process p[num];
    cout<<"Process ID"<<setw(15)<<"Burst time"<<setw(15)<<"Priority"<<endl;

    for(int i=0;i<num;i++){
        
        cin>>p[i].pid>>p[i].burst>>p[i].priority;
    }
    int temp=0,x=0;
    sort(p,p+num,comp);

    int wt[num+5],tat[num+5],total_wt=0,total_tat=0;
    wt[0] = 0; 
    
    for (int  i = 1; i < num ; i++ ) 
        wt[i] =  p[i-1].burst + wt[i-1] ; 
    
    for (int  i = 0; i < num ; i++) 
        tat[i] = p[i].burst + wt[i];
    
     for (int  i=0; i<num; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << p[i].pid <<"\t\t"<< p[i].burst <<"\t\t"<< p[i].priority<<"\t\t"<< wt[i] << "\t\t" << tat[i] <<endl; 
    } 
    cout << "\nAverage waiting time = "<< (float)total_wt / (float)num; 
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)num<<endl;
}


int main()
{

    int numOfProcess;
    cout<<"Enter The Number of processes : ";
    cin>>numOfProcess;
    addP(numOfProcess);
}
   