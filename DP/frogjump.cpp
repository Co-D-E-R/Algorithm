#include <bits/stdc++.h> 
using namespace std;
// void jump(int ind,int n,vector<int>&v,int ans,int &res){
//     if(ind>n){
//         return;
//     }
//     if(ind==n-1){
//         if(res>ans){
//             res=ans;
//         }
//     }
//     int val1=abs(v[ind+1]-v[ind]);
//     int val2=abs(v[ind+2]-v[ind]);
//     ans+=val1;
//     jump(ind+1,n,v,ans,res);
//     ans-=val1;
//     ans+=val2;
//     jump(ind+2,n,v,ans,res);
//     ans-=val2;

// }

// int frogJump(int n, vector<int> &v)
// {
//     int res=INT_MAX;
//     jump(0,n,v,0,res);
//     return res;
//     // Write your code here.
// }
//using Dp
int jump(int ind,vector<int>&v,vector<int>&dp){
    if(ind==0){
        return 0;
    }
    if(dp[ind]!=-1){return dp[ind];}
    int left=jump(ind-1,v,dp)+abs(v[ind]-v[ind-1]);
    int right =INT_MAX;
    if (ind > 1) {
        right =jump(ind - 2, v, dp) + abs(v[ind] - v[ind - 2]);
    }
    return dp[ind]=min(left,right);
    
}

int frogJump(int n, vector<int> &v)
{
    vector<int>dp(n+1,-1);
    return jump(n-1,v,dp);
    // Write your code here.
}

int main(){
    int n=8;
    vector<int>v = {7,4,4,2,6,6,3,4 };
    cout<<frogJump(n,v);
    return 0;
}