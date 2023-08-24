
#include<bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& v) {
        int f=0,t=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==5) f++;
            if(v[i]==10){
                if(f==0) return false;
                t++;
                f--;
            }
            else if(v[i]==20){
                if(f>0 && t>0){
                    t--;f--;
                }
                else if(f>=3){
                    f-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }


int main()
{
    vector<int>ans;
    vector<int>v = {5,5,5,5,20,20,5,5,20,5};
    cout<<lemonadeChange(v);
    return 0;
}