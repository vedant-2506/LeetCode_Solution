#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {

        int sz = s.size();
        int freq[26] = {0};

        for (int i = 0; i < sz; i++) {
            freq[s[i] - 'a']++;
        }

        priority_queue<pair<int, char>> heap;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                heap.push({freq[i], char(i + 'a')});
            }
        }

        pair<int, char> prev = {0, '#'};
        string ans = "";

        while (!heap.empty()) {
            auto [fr, ch] = heap.top();
            heap.pop();

            ans += ch;
            fr--;

            if (prev.first > 0) {
                heap.push(prev);
            }

            prev = {fr, ch};
        }

        if (prev.first > 0) {
            return "";
        }

        return ans;
    }
};

int main() {

    Solution sol;

    string s;

    cout << "Enter a string: ";
    cin >> s;

    string result = sol.reorganizeString(s);

    if (result == "") {
        cout << "Reorganization is not possible." << endl;
    }
    else {
        cout << "Original String : " << s << endl;
        cout << "Reorganized String : " << result << endl;
    }

    return 0;
}