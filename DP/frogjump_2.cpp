#include <bits/stdc++.h> 
using namespace std;

int check(int ind,int k,vector<int>&v,vector<int>&dp){
    if(ind==0) return 0;
    int right =INT_MAX;
    if(dp[ind]!=-1){return dp[ind];}
    for(int i=1;i<=k;i++){
      if (ind - i >= 0) {
        int left = check(ind - i, k, v, dp) + abs(v[ind] - v[ind - i]);
        // dp[ind]=min(right,left);
        right = min(right, left);
      }
    }
    return dp[ind]=right;
}
int minimizeCost(int n, int k, vector<int> &v){
    vector<int>dp(n+1,-1);
    return check(n-1,k,v,dp);

}
int main(){
    int n=4;
    int k=3;
    vector<int>v = {7,1,4,0};
    cout<<minimizeCost(n,k,v);
    return 0;
}