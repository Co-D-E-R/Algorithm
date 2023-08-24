#include<bits/stdc++.h>
using namespace std;


int findPlatform(int arr[], int dep[], int n)
    {
        // vector<pair<int,int>>pr;
        
        // for(int i=0;i<n;i++){
        //     pr.push_back({dep[i],arr[i]});
        // }
        
        sort(arr,arr+n);
        sort(dep,dep+n);
        int cnt=1,maxi=INT_MIN;
        int i=1,j=0;
        while(i<n && j<n){
            if(dep[j]>=arr[i]){
                cnt++;
                i++;
                
            }
            else{
                cnt--;
                j++;
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }

int main(){
    int n=6;
    int arr[n]={900,940,950,1100,1500,1800};
    int arr1[n]={910,1200,1120,1130,1900,2000};
    cout<<findPlatform(arr,arr1,n);
    return 0;
}