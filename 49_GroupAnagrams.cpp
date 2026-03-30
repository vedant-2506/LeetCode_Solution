#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string> >un;

        for(string s :strs){
            string sorts =s;
            sort(sorts.begin() , sorts.end() );
            un[sorts].push_back(s);
        }

        vector<vector<string>>ans;
        for(auto &e :un){
            ans.push_back(e.second);
        }

        return ans;
        
    }
};


int main(){
    Solution s;
    vector<string>strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>>ans = s.groupAnagrams(strs);

    for(auto &e :ans){
        for(string s :e){
            cout<<s<<" ";
        }
        cout<<endl;
    }

    return 0;
}