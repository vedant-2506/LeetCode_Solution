#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {

        // TC = O(n), SC = O(n)
        stack<char> stk;
        int i = 0;
        while (i < s.size()) {
            if (!stk.empty() && s[i] == stk.top()) {
                stk.pop();
                i++;
            }
            else {
                stk.push(s[i]);
                i++;
            }
        }

        string ans = "";
        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    Solution obj;
    string s;
    
    cout << "Enter a string: ";
    cin >> s;

    string result = obj.removeDuplicates(s);

    cout << "String after removing duplicates: "
         << result << endl;

    return 0;
}
