#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        //Nested Loop TC=O(n^2) SC=O(1)
        int sz=s.size();
        for(int i=0; i<sz; i++){
            for(int j=i; j<sz; j++){
                if(s[i]==s[j] && t[i]!=t[j])
                  return false;
                if(s[i] != s[j] && t[i] == t[j])
                  return false;
            }
        }
        return true;
        
        // //Hash map TC=O(n) SC=O(1)
        // unordered_map<char , int>un1;
        // unordered_map<char , int>un2;
        // for(int i=0; i<s.size(); i++){
        //     if(un1.count(s[i]) && un1[s[i]] != t[i])
        //         return false;

        //     if(un2.count(t[i]) && un2[t[i]] != s[i])
        //         return false;

        //     un1[s[i]] = t[i];
        //     un2[t[i]] = s[i];
        // }
        // return true;
    }
};

int main() {

    Solution sol;
    string s, t;

    cout << "Enter the first string: ";
    cin >> s;

    cout << "Enter the second string: ";
    cin >> t;

    bool result = sol.isIsomorphic(s, t);

    if (result) {
        cout << "\nThe strings are isomorphic." << endl;
    } else {
        cout << "\nThe strings are not isomorphic." << endl;
    }

    return 0;
}