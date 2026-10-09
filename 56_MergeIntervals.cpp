#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // TC = O(n log n)
        // SC = O(n)

        int sz = intervals.size();

        if (sz <= 1) return intervals;

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        vector<vector<int>> ans;

        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < sz; i++) {

            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            }
            else {
                ans.push_back({start, end});

                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        ans.push_back({start, end});

        return ans;
    }
};

int main() {

    Solution obj;
    int n;

    cout << "Enter the number of intervals: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid number of intervals.\n";
        return 0;
    }

    vector<vector<int>> intervals(n, vector<int>(2));

    cout << "\nEnter each interval as: start end\n";

    for (int i = 0; i < n; i++) {
        cout << "Interval " << i + 1 << ": ";
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<vector<int>> result = obj.merge(intervals);

    cout << "Merged Intervals:\n";
   

    for (auto interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "]\n";
    }


    return 0;
}