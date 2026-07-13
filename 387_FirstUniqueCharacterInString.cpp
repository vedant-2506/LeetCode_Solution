#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {

        // //nested loop TC=O(n^2) SC=(1) Time Limit Exceeded
        // for(int i=0; i<s.size(); i++){
        //     int count =0;
        //     for(int j=0; j<s.size(); j++){
        //         if(s[i] == s[j] ) count ++;
        //     }
        //     if(count == 1) return i;
        // }
        // return -1;
        
        // //using hashmap TC=(n) SC=O(n)
        // unordered_map<char , int>un;
        // for(char i : s){
        //     un[i]++;
        // }
        // for(int j=0; j<s.size(); j++){
        //     if(un[ s[j] ] == 1) return j;
        // }
        // return -1;
        

        //frequncy array TC=(n) SC=(1)
        int ferq[26] = {0};

        for(char ch : s){
            ferq[ch - 'a']++;
        }

        for(int i=0; i<s.size(); i++){
            if(ferq[ s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};

int main() {

    string s;

    cout << "Enter a string: ";
    cin >> s;

    Solution sol;
    int ans = sol.firstUniqChar(s);

    if(ans != -1) {
        cout << "\nIndex of the first unique character: " << ans << endl;
        cout << "Character: " << s[ans] << endl;
    }
    else {
        cout << "\nNo unique character found in the string." << endl;
    }

    return 0;
}