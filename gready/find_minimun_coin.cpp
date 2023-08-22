//Find the minimum number of coins using greedy method.
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>ans;
    vector<int>deno = {1,2,5,10,20,50,100,500,1000};
    int n=deno.size();
    int v;
    cin>>v;
    for(int i=n-1;i>=0;i--){
        while(v>=deno[i]){
            ans.push_back(deno[i]);
            v-=deno[i];
        }
    }
    cout<<ans.size()<<endl;
    return 0;
}