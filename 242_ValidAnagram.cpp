#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char , int >un;

        if(s.size() != t.size() ) return false;

        for(int i=0; i<s.size(); i++){
            un[s[i]]++;
        }

        for(int j=0; j<t.size(); j++){
            if(un.find(t[j]) == un.end() ) return false;
            un[t[j]]--;
            if( un[ t[j] ] <0) return false;
        }

        return true;
        
    }
};


int main(){
    Solution s;
    string str1 = "anagram";
    string str2 = "nagaram";

    cout<<s.isAnagram(str1, str2)<<endl;

    return 0;
}