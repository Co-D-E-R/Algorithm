#include<bits/stdc++.h>
using namespace std;
  bool check(int ind,int cnt,string &s,vector<vector<int>> &dp)
    {
        if(ind == s.size()){
            return (cnt == 0);
        }

        if(dp[ind][cnt]!=-1) return dp[ind][cnt];

        bool ans=false;
        if(s[ind]=='*'){
            ans|=check(ind+1,cnt+1,s,dp);
            if(cnt) ans|=check(ind+1,cnt-1,s,dp);
            ans|=check(ind+1,cnt,s,dp);
        }
        else{
             if(s[ind]=='('){
                ans=check(ind+1,cnt+1,s,dp);
            }
            else{
                if(cnt) ans=check(ind+1,cnt-1,s,dp);
             }
        }
        return dp[ind][cnt]=ans;

    }
    bool checkValidString(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        return check(0,0,s,dp);
    }
int main()
{
    int ans;
    string s="(((((*)))**";
    cout<<checkValidString(s);
    return 0;
}