#include <bits/stdc++.h> 
using namespace std;

 int f(int i,int j,vector<vector<int>>& v,int &n,vector<vector<int>>&dp){
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i == n-1){
            return v[i][j];
        }
        int down=v[i][j]+f(i+1,j,v,n,dp);
        int di=v[i][j]+f(i+1,j+1,v,n,dp);

        return dp[i][j]=min(down,di);
    }
    int minimumTotal(vector<vector<int>>& v) {
        int n=v.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(0,0,v,n,dp);
        
    }
 
    int main(){
    vector<vector<int>>v = {{2},{3,4},{6,5,7},{4,1,8,3} };
    cout<<minimumTotal(v);
    return 0;
}