#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
     
        int i=0;
        while( i<s.size() ){
            if(s[i] == 'c'){
                if(stk.empty() || stk.top() != 'b' ) return false;
                stk.pop();
                if( stk.empty() || stk.top() != 'a') return false; 
                stk.pop();
                
                i++;
            }
            else{
                stk.push( s[i] );
                i++;
            }
        }

        return stk.empty();
        
    }
};


int main(){
    Solution s;
    string str = "aabcbc";
    cout<<s.isValid(str)<<endl;
    return 0;
}