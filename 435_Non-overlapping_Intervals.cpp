#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        // TC = O(n log n), SC = O(1)
        sort(intervals.begin(), intervals.end(), [](
            vector<int>& a,
            vector<int>& b)
        {
            return a[0] < b[0];
        });

        int count = 0;
        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++) {

            if(intervals[i][0] < end) {
                count++;
                end = min(end, intervals[i][1]);
            }
            else {
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        return count;
    }
};

int main() {

    Solution obj;

    int n;

    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));

    cout << "Enter the intervals (start end):" << endl;

    for(int i = 0; i < n; i++) {
        cout << "Interval " << i + 1 << ": ";
        cin >> intervals[i][0] >> intervals[i][1];
    }

    int result = obj.eraseOverlapIntervals(intervals);

    cout << "\nMinimum number of intervals to remove: "
         << result << endl;

    return 0;
}