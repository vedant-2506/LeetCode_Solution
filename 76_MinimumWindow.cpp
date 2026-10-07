#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        // TC = O(n + m)
        // SC = O(1)

        vector<int> freq(128, 0);

        for(int i = 0; i < t.size(); i++) {
            freq[t[i]]++;
        }

        int required = 0;

        for(int i = 0; i < 128; i++) {
            if(freq[i] > 0) {
                required++;
            }
        }

        int lft = 0, rtg = 0, start = 0, have = 0;

        int minW = INT_MAX;

        vector<int> window(128, 0);

        while(rtg < s.size()) {

            char ch = s[rtg];
            window[ch]++;

            if(freq[ch] > 0 && window[ch] == freq[ch]) {
                have++;
            }

            while(lft <= rtg && required == have) {

                if(rtg - lft + 1 < minW) {
                    minW = rtg - lft + 1;
                    start = lft;
                }

                char ch = s[lft];
                window[ch]--;

                if(freq[ch] > 0 && window[ch] < freq[ch]) {
                    have--;
                }

                lft++;
            }

            rtg++;
        }

        return (minW == INT_MAX) ? "" : s.substr(start, minW);
    }
};

int main() {

    Solution obj;

    string s, t;


    cout << "Enter string S: ";
    cin >> s;

    cout << "Enter string T: ";
    cin >> t;

    string result = obj.minWindow(s, t);

   

    if(result.empty()) {
        cout << "No valid window found." << endl;
    }
    else {
        cout << "Minimum Window Substring: " << result << endl;
    }

    return 0;
}