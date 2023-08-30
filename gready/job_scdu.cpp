#include<bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

 static bool cmp(struct Job a,struct Job b){
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int>v;
        sort(arr,arr+n,cmp);
        int cnt=0,sum=0,maxi=-1;
        maxi=arr[0].dead;
        for (int i = 0; i < n; i++)
        {
            maxi=max(maxi,arr[i].dead);
        }
        int slot[maxi+1];
        for (int i = 0; i <= maxi; i++)
        {
            slot[i]=-1;
        }
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
                if(slot[j] == -1){
                    slot[j]=i;
                    cnt++;
                    sum+=arr[i].profit;
                    break;
                }
            }
        }
        v.push_back(cnt);
        v.push_back(sum);
        
        return v;
    } 
int main(){
    vector<int>ans;
    int n=4;
    struct Job jb[n];
    for(int i=0;i<n;i++){
        jb[i].id=i+1;
        cin>>jb[i].dead;
        cin>>jb[i].profit;
    }

    ans=JobScheduling(jb,n);

    for(auto num : ans){
        cout<<num<<" ";
    }

    return 0;


}