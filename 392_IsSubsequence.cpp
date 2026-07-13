#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {

        //two pointer TC=(m+n) SC=(1)
        int i=0  , j=0;
        while(i<s.size() && j<t.size()){
            if(s[i] == t[j]) i++;
            j++;
        }
        return (i == s.size());
        
    }
};

int main() {

    string s, t;

    cout << "Enter the first string (subsequence candidate): ";
    cin >> s;

    cout << "Enter the second string: ";
    cin >> t;

    Solution sol;

    bool result = sol.isSubsequence(s, t);

    cout << "\nResult: ";

    if(result) {
        cout << "\"" << s << "\" is a subsequence of \"" << t << "\"." << endl;
    }
    else {
        cout << "\"" << s << "\" is NOT a subsequence of \"" << t << "\"." << endl;
    }

    return 0;
}