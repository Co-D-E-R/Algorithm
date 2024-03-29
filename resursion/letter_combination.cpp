//Letter Combinations of a Phone Number
//Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

//A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
#include<bits/stdc++.h>
using namespace std;
      void letterCombinations(string digits, vector<string>& output, string &temp, vector<string>& pad, int index){
        if(index == digits.size()){
            output.push_back(temp);
            return;
        }
        string value = pad[digits[index]-'0'];
        for(int i=0; i<value.size(); i++){
            temp.push_back(value[i]);
            letterCombinations(digits, output, temp, pad, index+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> output;
        string temp;
        letterCombinations(digits, output, temp, pad, 0);
        return output;
    }
int main()
{
    vector<string>Ans;
    string dis="23";//candidates
    Ans=letterCombinations(dis);
    cout<<"[";
    for(auto &pr:Ans)
    {
        cout<<"[";
        for(auto &re:pr)
            cout<<re<<" ";
        cout<<"]";
    }
    cout<<"]";
    return 0;


}

