#include<bits/stdc++.h>
using namespace std;
int sub(int ind,vector<int>&v1,vector<int>&v2,int n,int k,int sum)
{
 
    if(ind==n)
    {
        if(sum==k){
            for(auto pr:v2)
            {
                cout<<pr<<" ";
            }
            cout<<endl;
        }
        return 0;
        
    }

    v2.push_back(v1[ind]);
    sum+=v1[ind];

    sub(ind+1,v1,v2,n,k,sum);

    sum-=v1[ind];
    v2.pop_back();

    sub(ind+1,v1,v2,n,k,sum);
}

int main()
{
    int n,k;
    vector<int>v1,v2;
    cout<<"\nEnter The Size :: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter The Element :: ";
        int x;
        cin>>x;
        v1.push_back(x);
    }
    cout<<"\nEnter the Sum ::";
    cin>>k;
    cout<<"\nSubsequence Array That's Equal to Sum "<<k<<"::\n";
    sub(0,v1,v2,n,k,0);
    return 0;

}