#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;

        for(int i=0; i<s.size(); i++){
            if(s[i] == ')' && !stk.empty() && stk.top() == '(') 
            stk.pop();

            else if(s[i] == '}' && !stk.empty() && stk.top() == '{') 
            stk.pop();

            else if(s[i] == ']' && !stk.empty() && stk.top() == '[') 
            stk.pop();

            else {
                stk.push( s[i] );
            }

        }


        return stk.empty();
        
    }
};


int main(){
    Solution s;
    string str = "([]:ff:))]";
    cout<<s.isValid(str)<<endl;
}