#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {

        unordered_map<char , int>un;

        for(int i=0; i<s.size(); i++){
            un[s[i]]++;
        }

        for(int j=0; j<s.size(); j++){
            if(un.find( s[j] ) != un.end() && un[ s[j] ] == 1) return j;
        }

        return -1;
        
    }
};


int main(){

    string s = "leetcode";

    Solution sol;
    int ans = sol.firstUniqChar(s);

    cout<<ans<<endl;

    return 0;
}