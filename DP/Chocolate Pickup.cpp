#include <bits/stdc++.h> 
using namespace std;
//recusion
//tc-->O(3^n X 3^m)
//sc-->O(N)
int f(int i,int j1,int j2,vector<vector<int>>&v,int r,int c){
   if(j1<0 || j1>=c || j2<0 || j2 > c){
       return -1e8;
   } 
   if(i==r-1){
       if(j1==j2){
           return v[i][j1];
       }
       else{
           return v[i][j1]+v[i][j2];
       }
   }
    int maxi=0;
   for(int x=-1;x<=1;x++){
       for(int y=-1;y<=1;y++){
           if (j1 == j2) {
             maxi = max(maxi, v[i][j1]+f(i + 1, j1 + x, j2 + y, v, r, c));
           } else {
             maxi = max(maxi, v[i][j1]+v[i][j2]+f(i + 1, j1 + x, j2 + y, v, r, c));
           }
       }
   }

   return maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &v) {
    return f(0,0,c-1,v,r,c);
}






//MEMOMIZATION
//Tc-->O(N X M X M) X 9
//Sc-->O(N X M) X O(N)stcak space


int f(int i,int j1,int j2,vector<vector<int>>&v,int r,int c,vector<vector<vector<int>>>&dp){
   
   if(j1<0 || j1>=c || j2<0 || j2 >= c){
       return -1e8;
   } 
   if(i==r-1){
       if(j1==j2){
           return v[i][j1];
       }
       else{
           return v[i][j1]+v[i][j2];
       }
   }
   if(dp[i][j1][j2]!=-1){
       return dp[i][j1][j2];
   }
    int maxi=-1e8;
   for(int x=-1;x<=+1;x++){
       for(int y=-1;y<=+1;y++){
           int val=0;
           if (j1 == j2) {
                val=v[i][j1];
           } else {
                val = v[i][j1]+v[i][j2];
           }
          val+=f(i + 1, j1 + x, j2 + y, v, r, c,dp);
          maxi=max(maxi,val);
       }
   }

   return dp[i][j1][j2]=maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &v) {
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return f(0,0,c-1,v,r,c,dp);
}










//Tabulation 
//Tc-->O(N X M X M) X 9
//Sc-->O(N X M)
int maximumChocolates(int n, int m, vector < vector < int >> & grid) {
  // Write your code here.
  vector < vector < vector < int >>> dp(n, vector < vector < int >> (m, 
  vector < int > (m, 0)));

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        dp[n - 1][j1][j2] = grid[n - 1][j1];
      else
        dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }

  //Outer Nested Loops for travering DP Array
  for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {

        int maxi = INT_MIN;

        //Inner nested loops to try out 9 options
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {

            int ans;

            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) ||
              (j2 + dj < 0 || j2 + dj >= m))

              ans += -1e9;
            else
              ans += dp[i + 1][j1 + di][j2 + dj];

            maxi = max(ans, maxi);
          }
        }
        dp[i][j1][j2] = maxi;
      }
    }
  }

  return dp[0][0][m - 1];

}

int main() {

  vector<vector<int> > matrix{
      {2,3,1,2},
      {3,4,2,2},
      {5,6,3,5},
  };

  int n = matrix.size();
  int m = matrix[0].size();

  cout << maximumChocolates(n, m, matrix);
}