#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:
    string removeStars(string s) {

        // //Stack Simulation TC=(n) SC=O(n)
        // stack<char>stk;
        // for(int i=0; i<s.size(); i++){
        //     if(!stk.empty() && s[i] == '*'){
        //         stk.pop();
        //         continue;
        //     }
        //     stk.push(s[i]);
        // }     
        // string ans="";   
        // while(!stk.empty()){
        //     ans+=stk.top();
        //     stk.pop();
        // }
        // reverse(ans.begin() , ans.end());
        // return ans;

        //In-place Stack Simulation (Two Pointer)
        //TC=O(n) SC=O(1)
        int j=0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '*'){
                j--;
            }
            else{
                s[j] = s[i];
                j++;
            }
        }
        return s.substr(0,j);
    }
};

int main() {

    Solution sol;
    string s;

    cout << "Enter a string (use '*' to represent a backspace): ";
    cin >> s;

    string result = sol.removeStars(s);

    cout << "\nString after processing: " << result << endl;

    return 0;
}