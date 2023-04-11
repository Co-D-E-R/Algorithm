#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M=1e9+7;
//recursive approch
ll re_pow(ll a,ll b)
{
    if(b==0)
        return 1;
    ll ans=pow(a,b/2);
    if(b%2==0)
        return  (ans * ans)%M;
    else
        return (((a*ans)%M)*ans)%M;
}
ll pow(ll a,ll b)
{
    ll ans=1;
    while(b>0)
    {
        if(b & 1)
            ans=(ans*a)%M;
            
        a = a*a % M;
        
        b>>=1;
    }
    return ans;
}
int main()
{
    ll a,b; 
    cout<<"\nEnter the Base ::";
    cin>>a;
    cout<<"\nEnter The Power ::";
    cin>>b;
    cout<<"\nRecusive Ans ::"<<re_pow(a,b);
    cout<<"\nIterative Ans::"<<pow(a,b);
    return 0;


}

