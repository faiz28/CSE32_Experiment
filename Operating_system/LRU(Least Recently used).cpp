#include<bits/stdc++.h>
using namespace std;
int FramSize,Pages[1000],store[1000],n;

void TakeInput()
{
    freopen("Input.txt","r",stdin);
    cout<<"Number of Pages : ";
    cin>>n;
    cout<<"Take input Page : ";
    for(int i=0;i<n;i++) cin>>Pages[i];

    cout<<"Fram size : ";
    cin>>FramSize;
}


int main()
{
    TakeInput();
    int PageFault=0,k=0,pos=0,pos_check=0;
    unordered_set<int> us;
    unordered_map<int,int> index;

    for(int i=0;i<n;i++)
    {
        if(us.size()<FramSize)
        {
            
            if(us.find(Pages[i])==us.end())
            {
                us.insert(Pages[i]);
                PageFault++;
            }
            index[Pages[i]]=i;
        }
        else{
            if(us.find(Pages[i])==us.end())
            {
                int lru=INT_MAX,val;
                for(auto it=us.begin();it!=us.end();it++)
                {
                    cout<<*it<<" ";
                    if(index[*it]<lru)
                    {
                        lru=index[*it];
                        val=*it;
                    }
                }
                cout<<endl;
                us.erase(val);
                us.insert(Pages[i]);
                PageFault++;
            }
            index[Pages[i]]=i;
        }
    }


    cout<<"Number of Page Fault : "<<PageFault<<endl;


}
