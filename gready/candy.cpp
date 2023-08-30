#include<bits/stdc++.h>
using namespace std;

int candy(vector<int>& v) {
        vector<int>left(v.size());
        vector<int>right(v.size());
        int cnt=1;
        int i=0;
        left[i++]=cnt;
        while(i && i<v.size()){
            if(v[i-1]<v[i]){
                cnt++;
                left[i]=cnt;
            }
            else{
                cnt=1;
                left[i]=1;
            }
            i++;
        }
        cnt=1;
        i=v.size()-1;
        right[i--]=cnt;
        while(i>=0 && i<v.size()){
            if(v[i+1]<v[i]){
                cnt++;
                right[i]=cnt;
            }
            else{
                cnt=1;
                right[i]=1;
            }
            i--;
        }
        int sum=0;
        for(int j=0;j<v.size();j++){
            sum+=max(left[j],right[j]);
        }
       
        return sum;
    }


    int main(){
    vector<int>v = {1,2,87,87,87,2,1};
    cout<<candy(v);
    return 0;
    }