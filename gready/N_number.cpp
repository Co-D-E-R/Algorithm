#include<bits/stdc++.h>
using namespace std;

 //solution 1   
struct meeting{
    int st;
    int en;
    int pos;
  };

static bool cmp(struct meeting a,struct meeting b){
    if(a.en < b.en) return true;
    else if(a.en > b.en) return false;
    else if(a.pos < b.pos) return true;
    return false; 
}

 int maxMeetings(int start[], int end[], int n)
    {
        struct meeting meet[n];
        // sort(start,start+n);
        // sort(end,end+n);
        for(int i=0;i<n;i++){
            meet[i].st=start[i],meet[i].en = end[i],meet[i].pos = i+1;
            
            
        }

        sort(meet,meet+n,cmp);

        vector<int> v;
            int fin = meet[0].en;
            v.push_back(meet[0].pos);

         for(int i=1;i<n;i++){
            if(meet[i].st > fin ){
                fin=meet[i].en;
                v.push_back(meet[i].pos);
            }

         }

        
        // cout<<cnt<<" ";
        return v.size();
    }

//solution 2 both are runing perfectly.
// int maxMeetings(int start[], int end[], int n)
//     {
//         vector<pair<int, int>> meet;
//         for(int i=0; i<n; i++){
//             meet.push_back({end[i], start[i]});
//         }   
//         sort(meet.begin(), meet.end());
//         int v = -1;
//         int ans = 0;
//         for(int i=0; i<n; i++){
//             if(meet[i].second > v){
//                 ans++;
//                 v = meet[i].first;
//             }
//         }
//         return ans;
//     }


int main(){
    int n=8;
    int arr[n]={75250,50074,43659,8931,11273,27545,50879,77924};
    int arr1[n]={112960,114515,81825,93424,54316,35533,73383,160252};
    cout<<maxMeetings(arr,arr1,n);
    return 0;
}