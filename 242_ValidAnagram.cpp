#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        // //by sorting 2 sting and check using to pointer TC= O(nlogn) SC = O(1)
        // if(s.size() != t.size()) return false;

        // sort(s.begin() , s.end());
        // sort(t.begin() , t.end());

        // int i=0 , j=0;
        // while(i<s.size() && j<t.size() ){
        //     if(s[i] != t[j] ) return false;
        //     i++;
        //     j++;
        // }

        // return true;


        // //2nd approch frecequency count approch TC = O(n) SC = O(1)
        // if(s.size() != t.size()) return false;

        // int freq[26] = {0};

        // for(char i : s){
        //     freq[i - 'a'] ++;
        // }

        // for(char i : t){
        //     freq[i- 'a'] --;
        // }

        // for(int c=1; c<26; c++){
        //     if(freq[c] != 0 ) return false;
        // }

        // return true;

        //3rd approch using hash table TC = O(n) SC = O(n)

        unordered_map<int , int >un;

        if(s.size() != t.size()) return false;

        for(int i =0; i<s.size();i++){
            un[s[i]]++;
        }

        for(int j=0;j<t.size();j++){
            if(un.find(t[j]) == un.end() ) return false;
            un[ t[j] ]--;
            if(un[ t[j] ] < 0 ) return false;
        }

        return true;

    }
};

int main() {
    Solution s;

    string str1, str2;

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    bool result = s.isAnagram(str1, str2);
    if(result) {
        cout << "It is an anagram." << endl;
    } else {
        cout << "It is not an anagram." << endl;
    }

    return 0;
}