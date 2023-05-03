//print all the permutation of array >> 
#include<bits/stdc++.h>
using namespace std;

void pre(vector<vector<int>>&res,vector<int>&temp,vector<int>&v,int freq[])
{
    if(v.size()==temp.size())
    {
        res.push_back(temp);
    }
    for(int i=0;i<v.size();i++)
    {
        if(!freq[i])
        {
            temp.push_back(v[i]);
            freq[i]=1;//to keep the track of visited array;
            pre(res,temp,v,freq);
            freq[i]=0;
            temp.pop_back();
        }
    }
}
vector<vector<int>>permutation(vector<int>&v)
{
    vector<vector<int>>res;
    vector<int>temp;
    int freq[v.size()]={0};
    for(int i=0;i<v.size();i++)
    {
        freq[i]=0;
    }
    pre(res,temp,v,freq);
    return res;
}

int main()
{
    vector<int>v{1,2,3};
    vector<vector<int>>ans;
    ans=permutation(v);
    cout<<"[";
    for(auto &pr:ans)
    {
        cout<<"[";
        for(auto &re:pr)
        {
            cout<<" "<<re<<" ";
        }
        cout<<"]";
    }
    cout<<"]";

    return 0;

}
