//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        i--;
        int clear=0,set=0;
        int find=(num >>i)& 1;//To find the bit
        set=((1<<i)|num);
        clear=(~(1<<i)&num);
        cout<<find<<" "<<set<<" "<<clear<<endl; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends