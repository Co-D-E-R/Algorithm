#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(struct Item a,struct Item b){
        double r1 = (double)a.value/(double)a.weight;
        double r2 = (double)b.value/(double)b.weight;
        return r1 > r2;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
       sort(arr,arr+n,cmp);
        
        int i=0;
        double val=0.0;
        while(i<n){
            if(W>=arr[i].weight){
                W-=arr[i].weight;
                val+=arr[i].value;
            }
            else{
                val+=(arr[i].value*((double)W/(double)arr[i].weight));
                break;
            }
            i++;
        }
        return val;
    }
        
};