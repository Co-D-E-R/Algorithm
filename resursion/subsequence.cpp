#include<bits/stdc++.h>
using namespace std;
int sub(int ind,vector<int>&v1,vector<int>&v2,int n)
{
    if(ind==n)
    {
        for(auto pr:v2)
        {
            cout<<pr<<" ";
        }
        if(v2.size()==0)
        {
            cout<<"{}";
        }
        cout<<endl;
        return 0;
    }
    v2.push_back(v1[ind]);
    sub(ind+1,v1,v2,n);
    v2.pop_back();
    sub(ind+1,v1,v2,n);
}

int main()
{
    int n;
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
    cout<<"\nSubsequence Array ::\n";
    sub(0,v1,v2,n);
    return 0;

}