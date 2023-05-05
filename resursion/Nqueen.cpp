//NQueen problem>> 
#include<bits/stdc++.h>
using namespace std;
//solution 1
bool safe(int row,int col,vector<string>&board,int n)
    {
        int dup1=row;
        int dup2=col;
        while(row>=0 &&col>=0)
        {
            if(board[row][col]=='Q') return false;
            row--;col--;
        }
        row=dup1;
        col=dup2;
        while(col>=0)
        {
            if(board[row][col]=='Q') return false;
            col--;
        }
        row=dup1;
        col=dup2;
        while(row<n && col>=0)
        {
            if(board[row][col]=='Q') return false;
            row++;col--;
        }
        return true;

}
void Nqueen(int col,vector<string>&board,vector<vector<string>>&ans,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(safe(row,col,board,n))
            {
                board[row][col]='Q';
                Nqueen(col+1,board,ans,n);
                 board[row][col]='.';
            }
        }
}
vector<vector<string>> solveNQueens(int n) {
        vector<string>str(n);
        vector<vector<string>>ans;
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
           str[i]=s;
        }
        Nqueen(0,str,ans,n);
        return ans;
}
//solution 2


void Nqueen(int col,vector<string>&board,vector<vector<string>>&ans,int n, vector<int> &left, vector<int>&upper, vector<int> &lower)
{
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
          if(left[row]==0 && upper[(n-1)+(col-row)]==0 && lower[row+col]==0)
          {
              board[row][col]='Q';
              left[row] =1;
              lower[row+col]=1;
              upper[(n-1)+(col-row)]=1;
              Nqueen(col+1,board,ans,n,left,upper,lower);
              board[row][col]='.';
              left[row] =0;
              lower[row+col]=0;
              upper[(n-1)+(col-row)]=0;


          }
        }
}
vector<vector<string>> solveNQueens(int n) {
        vector<string>str(n);
        vector<vector<string>>ans;
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
           str[i]=s;
        }
        vector<int> left(n,0),upper(2*n-1,0),lower(2*n-1,0);
        Nqueen(0,str,ans,n,left,upper,lower);
        return ans;
}

int main()
{
    int n;
    cout<<"Enter the number of queens ::";
    cin>>n;
    vector<vector<string>>ans;
    ans=solveNQueens(n);
    cout<<"[";
    for(auto &pr:ans)
    {
        cout<<"[";
        for(auto &re:pr)
        {
            cout<<" "<<re<<"  ";
        }
        cout<<"]";
    }
    cout<<"]";

    return 0;

}
