#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> ans;

        for (auto i : intervals) {
            ans.push_back(i);
        }

        ans.push_back(newInterval);

        sort(ans.begin(), ans.end(), [](const vector<int>& a,
                                        const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> result;

        int start = ans[0][0];
        int end = ans[0][1];

        for (int i = 1; i < ans.size(); i++) {

            if (ans[i][0] <= end) {
                end = max(end, ans[i][1]);
            }
            else {
                result.push_back({start, end});

                start = ans[i][0];
                end = ans[i][1];
            }
        }

        result.push_back({start, end});

        return result;
    }
};

int main() {

    Solution obj;

    int n;

    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));

    cout << "\nEnter the intervals (start end):\n";

    for (int i = 0; i < n; i++) {
        cout << "Interval " << i + 1 << ": ";
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<int> newInterval(2);

    cout << "\nEnter new interval (start end): ";
    cin >> newInterval[0] >> newInterval[1];

    vector<vector<int>> result = obj.insert(intervals, newInterval);

    cout << "Intervals after insertion and merging:\n";
    

    for (auto interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}