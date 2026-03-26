#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char>stk;

        int i=0; 
        while(i<word.size()){
            stk.push(word[i]);
            if(word[i] == ch) break;
            i++;
        }

        if(i == word.size()) return word;
        else{
        string ans="";
        while(!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }

        i++;
        while(i<word.size()){
            ans+=word[i];
            i++;
        }

        return ans;
        }
    
    }
};

int main(){
    Solution s;
    string word = "abcdefd";
    char ch = 'd';
    cout<<s.reversePrefix(word,ch)<<endl;
}