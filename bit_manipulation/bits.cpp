#include<bits/stdc++.h>
using namespace std;

void print(int num){
    for(int i=10;i>=0;--i){
        cout<<((num>>i)&1);
    }
    cout<<endl;
}
int main(){
    print(9);
    int a=9;
    int i=2;
    //To Check if bits are set or not 
    if((a & (1<< i)) !=0)
    {
        cout<<"Bit Set"<<endl;
    }
    else{
        cout<<"Not Set"<<endl;
    }
    //bit set     here i = any number;
    print(a|(1<<i));
    //uset the bit
    print(a&(~(1<<i)));

    //toggle :- work when we use xor(^) operator
    print(a^(1<<2));
    print(a^(1<<i));
    //to count the number of set bit
    int cnt=0;
    for(int i=31;i>=0;--i){
        if((a&(1<<i))!=0){
            cnt++;
        }
    }
    cout<<cnt<<endl;

    cout<<__builtin_popcount(a)<<endl;
    cout<<__builtin_popcountll((1LL<<35)-1)<<endl;
}

