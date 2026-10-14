
#include <iostream>
using namespace std;

// Simulate the LeetCode API for local testing
int firstBad;

// Returns true if the version is bad
bool isBadVersion(int version) {
    return version >= firstBad;
}

class Solution {
public:
    int firstBadVersion(int n) {

        // Binary Search TC = O(log n), SC = O(1)

        int lo = 1, hi = n;

        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            bool res = isBadVersion(mid);

            if(res == false) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        return lo;
    }
};

int main() {
    Solution obj;

    int n;

    cout << "Enter the total number of versions: ";
    cin >> n;

    if(n < 1) {
        cout << "Invalid input! n must be at least 1.\n";
        return 0;
    }

    cout << "Enter the first bad version (1 to " << n << "): ";
    cin >> firstBad;

    if(firstBad < 1 || firstBad > n) {
        cout << "Invalid first bad version!\n";
        return 0;
    }


    int result = obj.firstBadVersion(n);

    cout << "First bad version: " << result << endl;
   
    return 0;
}
