//You are given an array/list 'ARR' of 'N' positive integers and an integer 'K'.
//your task is to check if there exists a subset in 'ARR' with a sum equal to 'K'.
//Note: Return true if there exists a subset with sum equal to 'K'. Otherwise,
//return false.
#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>

//Recursion
//Tc-->O(2^n)
//sc-->O(N)

bool f(int ind,int k,vector<int>&arr){

  if (k == 0) {
    return true;
  }

    if(ind == 0){
        return arr[0] == k;     
    }

    bool no = f(ind-1,k,arr);
    bool take = false;
    if(k>=arr[ind]){
        take=f(ind-1,k-arr[ind],arr);
    }

    return take || no;
   
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    return f(n-1,k,arr);
}
int main() {

  vector<int>v{4,3,2,1};

  int n = 4;
  int k = 5;

  cout << subsetSumToK(n, k, v);
}
//Memoization
//Tc-->o(N X K)
//sc-->O(N x K)+O(N)
#include <bits/stdc++.h>
bool f(int ind,int k,vector<int>&arr,vector<vector<int>>&dp){

  if (k == 0) {
    return true;
  }
    if(dp[ind][k]!=-1){
        return dp[ind][k];
    }
    if(ind == 0){
        return arr[0] == k;     
    }

    bool no = f(ind-1,k,arr,dp);
    bool take = false;
    if(k>=arr[ind]){
        take=f(ind-1,k-arr[ind],arr,dp);
    }

    return dp[ind][k]=take || no;
   
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
}
//tabulation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>>dp(n+1,vector<bool>(k+1,false));
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    if (arr[0] <= k) {
        dp[0][arr[0]] = true;
    }

    for(int ind=1;ind<n;ind++){
        for(int tar=1;tar<=k;tar++){
            bool no = dp[ind-1][tar];

            bool take = false;
            if(tar>=arr[ind]){
                take=dp[ind-1][tar-arr[ind]];
            }
            dp[ind][tar]=take||no;
        }
    }
   return  dp[n-1][k];
}