#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        // //Filter String  TC=O(n) SC=O(n)
        // string clean="";
        // for(char ch : s){
        //     if( isalnum(ch) ){
        //         clean += tolower(ch);
        //     }
        // }
        // string rev=clean;
        // reverse(rev.begin() , rev.end());

        // return (rev == clean);

        // //Filter String + Two Pointers TC=O(n) SC=O(n)
        // string ans="";
        // for(char ch : s){
        //     if(isalnum(ch)){
        //         ans+=tolower(ch);
        //     }
        // }
        // int i=0 , j=ans.size()-1;
        // while(i<j){
        //     if(ans[i] != ans[j] ) return false;
        //     i++;
        //     j--;
        // }
        // return true;


        //two pointer + inpalce TC=(n) SC=O(1)
        int left=0 , right=s.size()-1;
        while(left<right){
            while(left<right && !isalnum( s[left] )) left++;
            while(left<right && !isalnum( s[right] )) right--;

            if(tolower(s[left]) !=  tolower(s[right]) ) return false;

            left++;
            right--;
        }
        return true;
    } 
};

int main() {

    Solution obj;
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    bool result = obj.isPalindrome(str);

    cout << "\nResult: ";

    if(result)
        cout << "The given string is a palindrome." << endl;
    else
        cout << "The given string is not a palindrome." << endl;

    return 0;
}