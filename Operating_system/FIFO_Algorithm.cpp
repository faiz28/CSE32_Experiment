#include<bits/stdc++.h>
using namespace std;


int main()
{
    int FramSize,Page[1000],store[1000],n;

    cout<<"Number of Pages : ";
    cin>>n;
    cout<<"Take input Page : ";
    for(int i=0;i<n;i++) cin>>Page[i];
    cout<<"Fram size : ";
    cin>>FramSize;

    int PageFault=0,k=0;
    for(int i=0;i<n;i++)
    {
        if(k<FramSize)
        {
            int check=0;
            for(int j=0;j<k;j++)
            {
                if(Page[i]==store[j])
                {
                    check=1;
                }
            }
            if(!check)
            {
                store[k++]=Page[i];
                PageFault++;
            }
            
        }
        else{
            int check=0;
            
            for(int j=k-FramSize;j<k;j++)
            {
                if(Page[i]==store[j])
                {
                   check=1;
                }
            }
        
            if(check) continue;
            else 
            {
               store[k++]=Page[i];
                PageFault++;
            }
        }
    }

    cout<<"Number of Page Fault : "<<PageFault<<endl;


}
