#include<bits/stdc++.h>
using namespace std;
/***
 * Given a array a of n intergers .All the interger are present in even count except one odd.
 * find the odd in o(N) time and O(1)Space
*/
// 9
// 2 4 6 7 7 4 2 2 2 

int main(){
    int n;
    cin>>n;
    int x;
    int res=0;
    for(int i=0;i<n;i++){
        cin>>x;
        res ^=x;
    }
    cout<< res<<endl;

}
