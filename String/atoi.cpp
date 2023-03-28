#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
        int atoi(string s)
        {
            const int len=s.size();
            if(len==0)
            {
                return 0;
            }
            int ind=0;
            //skip all the white space
            while(ind<len && s[ind]==' ')
            {
                ++ind;
            }
            //check the sign case
            bool isNeg=false;
            if(ind < len)
            {
                if(s[ind]=='-')
                {
                    isNeg=true;
                    ++ind;
                }
                else if(s[ind]=='+'){
                    ++ind;
                }
            }
            int result=0;
            //convert digit to integer
            while(ind<len && isdigit(s[ind]))
            {
                //convert char 5(53) - 0(48) =5(int value) 
                int digit= s[ind]- '0';

                if(result > (INT_MAX / 10) || (result == (INT_MAX/10) && digit > 7))//Overflow Condition
                {
                    return isNeg ? INT_MIN: INT_MAX;
                }

                result=(result * 10)+digit;
                ++ind;
            }
            return isNeg ? -result: result;
        }


    private:
        bool isdigit(char ch)
        {
            return ch>='0' && ch <='9';
        }
  
};
int main()
{
    int res;
    solution sl;
    string s;
    cout<<"\nEnter The String :: ";
    cin>>s;
    res=sl.atoi(s);
    cout<<"\nConverted Result ::"<<res<<endl;
    return 0;
}
