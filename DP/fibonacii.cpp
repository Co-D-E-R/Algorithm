#include<bits/stdc++.h>
using namespace std;

//Memozation
//Tc -> O(n) Because there is linear pattern that why
//sc -> O(n) + O(n) = O(n)
int f(int n,vector<int>&dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){return dp[n];}

    return dp[n]=f(n-1,dp)+f(n-2,dp);
}

//Tabulation
//Tc-> o(N);
//Sc-> O(N);
// int main(){
//     int n;
//     cin>>n;
//     vector<int>dp(n+1);
//     dp[0]=0;
//     dp[1]=1;
//     for(int i=2;i<=n;i++){
//         dp[i]=dp[i-1]+dp[i-2];
//     }
//     for(auto num:dp){
//         cout<<num<<" ";
//     }

//     return 1;
// }
//Space Optimization;
//Tc->O(N)
//sc ->O(1)

int main(){
    int n;
    cin>>n;
    int prev2=0,prev=1;
    int curri;
    for(int i=2;i<=n;i++){
        curri=prev2+prev;
        prev2=prev;
        prev=curri;
    }
    cout<<prev;

    return 1;
}