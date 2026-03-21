#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>stk;

        for(const string &s : tokens){
            if(s == "+"){
                int rt=stk.top() ; stk.pop();
                int lf=stk.top() ; stk.pop();

                int ans = lf+rt;
                stk.push(ans);
            }
            else if(s == "-"){
                int rt=stk.top() ; stk.pop();
                int lf=stk.top() ; stk.pop();

                int ans=lf-rt;
                stk.push(ans);
            }
            else if(s == "*"){
                int rt=stk.top() ; stk.pop();
                int lf=stk.top() ; stk.pop();

                int ans = lf*rt;
                stk.push(ans);
            }
            else if(s == "/"){
                int rt=stk.top() ; stk.pop();
                int lf=stk.top() ; stk.pop();

                int ans = lf/rt;
                stk.push(ans);
            }
            else{
                stk.push(stoi(s));
            }
        }


        return stk.top();
        
    }
};

int main(){
    Solution s;
    vector<string> tokens = {"2","1","+","3","*"};
    cout<<s.evalRPN(tokens)<<endl;
    return 0;
}