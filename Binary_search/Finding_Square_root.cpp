//Finding the n root of a given number using binary search method
#include<bits/stdc++.h>
using namespace std;
double multi(double number,int n)
{
    double ans=1.0;
    for(int i=1;i<=n;i++)
    {
        ans=ans*number;
    }
    return ans;
}
int main()
{
    int n,m;
    cout<<"\nEnter the number ::";
    cin>>m;
    cout<<"\nEnter The Root Value ::";
    cin>>n;
    double l=1,h=m;
    double e=1e-6;//10^-6 
    while((h-l)>e)
    {
        double mid=(l+h)/2.0;
        if(multi(mid,n)<m){
            l=mid;
        }
        else{
            h=mid;
        }
    }
    cout<<"\nlow ::"<<l<<"high ::"<<h<<endl;
    cout<<"By Checking Value ::";
    cout<<pow(m,(double)(1.0/(double)n));
    return 0;
}