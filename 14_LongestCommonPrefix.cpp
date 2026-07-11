#include<vector>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        // //Brute Force Horizontal Character Comparison TC=O(m*n) SC=O(1)
        // if(strs.empty()) return "";
        // string ans="";
        // for(int i=0; i<strs[0].size(); i++){
        //     char ch=strs[0][i];
        //     for(int j=1; j<strs.size(); j++){
        //         if(i>=strs[j].size() || strs[j][i] != ch)
        //             return ans;
        //     }
        //     ans+=ch;
        // }
        // return ans;


        //Sorting + First & Last String Comparison TC=O(nlogn) SC=O(m)
        sort(strs.begin() , strs.end());
        string first = strs.front();
        string last = strs.back();
        string ans="";
        for(int i=0; i<min(first.size() , last.size() ); i++){
            if(first[i] != last[i]) break;
            ans+=first[i];
        }
        return ans;
    }
};

int main() {

    int n;

    cout << "Enter the number of strings: ";
    cin >> n;

    vector<string> strs(n);

    cout << "Enter the strings:\n";
    for(int i = 0; i < n; i++) {
        cout << "String " << i + 1 << ": ";
        cin >> strs[i];
    }

    Solution obj;

    string result = obj.longestCommonPrefix(strs);

    cout << "\nLongest Common Prefix: ";

    if(result.empty())
        cout << "No common prefix found.";
    else
        cout << result;

    cout << endl;

    return 0;
}