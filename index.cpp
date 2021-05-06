#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> valid;
    
    void backtrack(string &s , int open , int close , int max)
    {
        
        if(s.length() == max*2){
            valid.push_back(s);
            return ;
        }
        if(open < max){
            //do
            s.push_back('(');
            //recurse
            backtrack(s, open +1 , close, max);
            //undo
            s.pop_back();
            
        }
        if(close < open ){
            s.push_back(')');
            backtrack(s, open , close+1 , max);
            s.pop_back();
        }
    }
    
    
    
    vector<string> generateParenthesis(int n) {
        string s;
        backtrack(s,0,0,n);
        return valid;  
    }
};
int main(){
    Solution s1;
    s1.generateParenthesis(2);
    return 0;
}