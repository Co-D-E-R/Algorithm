#include <bits/stdc++.h> 
using namespace std;

    int numSquares(int n) {
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int tr=1;tr<n+1;tr++){
            for(int s=1;s<tr+1;s++){
                int sq=s*s;
                if((tr-sq) < 0){
                    break;
                }
                dp[tr]=min(dp[tr],1+dp[tr-sq]);
            }
            
        }
        
        return dp[n];
        
    }
int main(){
   int n=12;
    cout<<numSquares(n);
    return 0;
}