#include<iostream>
#include<string>
#include<cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        string ans = "";
        
       for(char ch : s){
        if(isalnum(ch)){
            ans+=tolower(ch);
        }
       }

        int i=0 , j=ans.size()-1;

        while(i<j){
            if(ans[i] != ans[j] ) return false;
            i++;
            j--;
        }

        return true;
    } 
};

int main(){
    Solution s;
    string str = "A man, a plan, a canal: Panama";
    cout << s.isPalindrome(str) << endl;
    return 0;
}