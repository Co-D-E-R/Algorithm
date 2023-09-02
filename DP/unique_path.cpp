#include <bits/stdc++.h> 
using namespace std;
  // int path(int up,int left,int ans,int &res,vector<vector<int>>&dp){
    //     if(up<0 || left<0){
    //         return 0;
    //     }
    //     if(up==0 && left == 0){
    //         return 1;
           
    //     }
    //     if(dp[up][left]!=-1){return dp[up][left];}
    //     int up1=path(up-1,left,ans,res,dp);
    //     int up2=path(up,left-1,ans,res,dp);
    //      return dp[up][left]=up1+up2;
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) {dp[i][j]=1;continue;}
                else{
                    int up1=0,up2=0;
                    if(i>0) up1=dp[i-1][j];
                    if(j>0) up2=dp[i][j-1];
                    dp[i][j]=up1+up2;
                }
            }
        }
        return dp[m-1][n-1];

        
    }
    int main(){
        int m=3;
        int n=2;
        cout<<uniquePaths(m,n);
        return 0;

    }
//space optimal 

      int uniquePaths(int m, int n) {
        vector<int>dp(n,0);
        for(int i=0;i<m;i++){
            vector<int>temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    temp[j]=1;
                    continue;
                }
                int up=0;
                int left=0;
                if(i>0) up = dp[j];
            
                if(j>0) left=temp[j-1];
                temp[j]=up+left;
            }
            dp=temp;
        }
        return dp[n-1];
        
    }