#include <bits/stdc++.h> 
using namespace std;
int robb(int ind,vector<int>&nums,vector<int>&dp){
        if(ind<0){
            return 0;
        }
        if(ind==0){
            return nums[ind];
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int pick=robb(ind-2,nums,dp)+nums[ind];
        int not_pick=robb(ind-1,nums,dp)+0;

        return dp[ind]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        vector<int> v,v2;
        vector<int>dp(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);
        if(nums.size()==1){
            return nums[0];
        }
        for(int i=0;i<nums.size()-1;i++){
            v.push_back(nums[i]);
        }
        for(int i=1;i<nums.size();i++){
            v2.push_back(nums[i]);
        }
        for(auto num:v2){
            cout<<num<<" ";
        }

         int ans1=robb(v.size()-1,v,dp);

         int ans2=robb(v2.size()-1,v2,dp2);
         cout<<ans2<<" ";

         return max(ans1,ans2);
        
    }
    int main(){
    vector<int>v = {1,2,3,1};
    cout<<rob(v);
    return 0;
}

//space optimal
int robb(vector<int>&temp){
        int prev=temp[0];
        int prev2=0;
        int curri;
        for(int i=1;i<temp.size();i++){
            int take=temp[i];
            if(i>1)
                take+=prev2;
            int nott=0+prev;
            int curri=max(take,nott);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
   int rob(vector<int>& nums) {
        vector<int>v,v1;
        if(nums.size()==1){
            return nums[0];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0) v.push_back(nums[i]);
            if(i!=nums.size()-1) v1.push_back(nums[i]);
        } 
        // int ans1=robb(v);
        // int ans2=robb(v1);
        return max(robb(v),robb(v1));
              
    }