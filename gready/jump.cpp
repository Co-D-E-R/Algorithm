#include<bits/stdc++.h>
using namespace std;
    bool canJump(vector<int>& v) {
        int n=v.size()-1;
        if(v.size()==1) return true;
        int val=0;
        for(int i=0;i<v.size();i++){
            val=max(val,i+v[i]);
            if(val==i) return false;
            else{
                if(val>=n){
                    return true;
                }
            }
        }
        return true;
    }
int main()
{
    vector<int> v = {2,3,1,1,4};
    cout<<canJump(v);

}

// public:
//     bool canJump(vector<int>& nums) {
//         if(nums.size()==1)
//             return true;
//         int n=nums.size()-1;
//         int reach=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             reach=max(reach,i+nums[i]);
//             if(reach==i)
//                 return false;
//             else
//             {
//                 if(reach>=n)
//                 {
//                     return true;
//                 }
//             }
//         }
//         return true;
        
//     }
// };