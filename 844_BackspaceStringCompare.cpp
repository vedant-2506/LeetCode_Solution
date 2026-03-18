#include<iostream>
#include<stack>
#include<string>

using namespace std;
class Solution {
public:
    bool backspaceCompare(string s, string t) {

        stack<char> stk1,stk2;

        for(const char & c :s){
            if(c!= '#')stk1.push(c);
            else if(!stk1.empty()) stk1.pop();
        }
        string ans1="";
        while(!stk1.empty() ){
            ans1 += stk1.top();
            stk1.pop();
        }  

      for(const char &d :t){
        if(d!='#')stk2.push(d);
        else if(!stk2.empty())stk2.pop();
      }  
   
      string ans2="";
      while(!stk2.empty()){
        ans2+=stk2.top();
        stk2.pop();
      }

      return ans1 == ans2;
    }
};


int main(){
    Solution s;
    string str1 = "ab#c";
    string str2 = "ad#c";
    cout<<s.backspaceCompare(str1,str2)<<endl;
}