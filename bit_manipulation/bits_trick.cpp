#include<bits/stdc++.h>
using namespace std;

void print(int num){
    for(int i=10;i>=0;--i){
        cout<<((num>>i)&1);
    }
    cout<<endl;
}
int main(){
    // //Changing a character in uppercase to lowercase using bit manipulation
    // for(char c ='A';c<='E';++c){ //in uppercase) A => 5th bit are not set (1000001
    //     cout<<c<<endl;
    //     print(int(c));
    // }
    //    for(char c ='a';c<='e';++c){ //in lowercase) a => 5th bit are set (1100001)
    //     cout<<c<<endl;
    //     print(int(c));
    // }
    // char c='A';
    // char a= c | (1<<5);
    // cout<<a<<endl;
    // cout<<char(a & (~(1<<5)))<<endl;
    // cout<<char('C'|' ')<<endl;
    // cout<<char('c' & '_')<<endl;




    //clear the lsb up to ith bit
    // print(59);
    // int a =59;
    // int i=4;
    // int b= ( a & (~((1<<(i+1))-1)));
    // print(b);
    //  i=3;
    // int c=(a & ((1<<(i+1))-1));//clear the msb up to ith bit
    // print(c);



    //swap the number of a and b using xor(^) operation
    int a=4,b=6;

    a= a^b;

    b=b^a;//b---> a
    //b=b^(a^b)==>b^b^a

    a=a^b;//a--->b
    //a=(a^b)^a ==>a^a^b-->b
    cout<<a<<" "<<b<<endl;


}
