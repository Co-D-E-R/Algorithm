#include<bits/stdc++.h>
using namespace std;
    void comb(int cursum,int ind,vector<vector<int>> &res,vector<int>&temp,vector<int>&v,int target)
    {
        if(cursum>target) return;
        if(cursum==target)
        {
            res.push_back(temp);
            return;
        }

        for(int i=ind;i<v.size();i++)
        {
            temp.push_back(v[i]);
            cursum+=v[i];
            comb(cursum,i,res,temp,v,target);
            temp.pop_back();
            cursum-=v[i];
        }


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>temp;
        comb(0,0,res,temp,candidates,target);
        return res;
    }
int main()
{
    vector<vector<int>>Ans;
    vector<int> v={2,3,6,7};//candidates
    int target=7;
    Ans=combinationSum(v,target);
    cout<<"[";
    for(auto &pr:Ans)
    {
        cout<<"[";
        for(auto &re:pr)
            cout<<re<<" ";
        cout<<"]";
    }
    cout<<"]";
    return 0;


}