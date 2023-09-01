#include <bits/stdc++.h> 
using namespace std;
//Tc->O(N)+O(N)
//SC->O(N)
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

        int select=robb(ind-2,nums,dp)+nums[ind];
        int non_select=robb(ind-1,nums,dp)+0;

        return dp[ind]=max(select,non_select);

    }

    int main(){
    vector<int>v = {1,2,3,1};
    cout<<rob(v);
    return 0;
}
//Tc->O(N) and SC->O(N)
//Tabulation
int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,0);
        dp[0]=nums[0];
        int neg=0;
        for(int i=1;i<n;i++){
            int take=nums[i];if(i>1) take+=dp[i-2];
            int nontake=dp[i-1];
            dp[i]=max(take,nontake);
        }
        return dp[n-1];
        
        
    }


//Space optimation t->O(N),S->O(1)
int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        int curri;
        for(int i=1;i<n;i++){
            int take=nums[i];if(i>1) take+=prev2;
            int nontake=0+prev;
            curri=max(nontake,take);
            prev2=prev;
            prev=curri;
        }
        return prev;
        
        
    }