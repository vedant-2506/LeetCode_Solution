#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        //
        // for(int i=0; i<s.size(); i++){
        //     string A = s.substr(0 , i+1);
        //     for(int j=i+2; j<s.size(); j++){
        //         string B = s.substr( j , i+1);

        //         if( A == B ) return true;
        //     }
        // }
        // return false;

        // //Pattern Construction TC=O(n^2) SC=O(n)
        // int sz=s.size();
        // for(int len=1; len<= (sz/2); len++){
        //     if(sz%len != 0) continue;

        //     string pat = s.substr(0 , len);
        //     string temp="";
        //     while(temp.size() < sz){
        //         temp+=pat;
        //     }

        //     if(temp == s ) return true;
        // }
        // return false;


        //String Concatenation Trick TC=O(n) SC=O(n)
        string  pat = s+s;
        pat = pat.substr(1, pat.size()-2 );

        return pat.find(s) != string::npos;
    }
};

int main() {

    Solution sol;
    string s;

    cout << "Enter a string: ";
    cin >> s;

    bool result = sol.repeatedSubstringPattern(s);

    cout << "\nResult: ";

    if(result) {
        cout << "\"" << s << "\" can be formed by repeating one of its substrings." << endl;
    }
    else {
        cout << "\"" << s << "\" cannot be formed by repeating one of its substrings." << endl;
    }

    return 0;
}