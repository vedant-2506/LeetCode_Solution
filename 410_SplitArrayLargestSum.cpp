#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {

        // TC = O(nlog n) SC = O(1)
        int lo = 0, hi = 0;
        for(int i = 0; i < nums.size(); i++) {
            lo = max(lo, nums[i]);
            hi += nums[i];
        }

        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(canSplit(nums, mid, k)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }

    bool canSplit(vector<int>& nums, int x, int k) {
        int numP = 1, sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(sum + nums[i] > x) {
                numP++;
                sum = nums[i];

                if(numP > k) {
                    return false;
                }
            }
            else {
                sum += nums[i];
            }
        }

        return true;
    }
};

int main() {

    Solution obj;

    int n, k;

    cout << "Enter the number of elements: ";
    cin >> n;

    if(n <= 0) {
        cout << "Invalid array size!\n";
        return 0;
    }

    vector<int> nums(n);

    cout << "\nEnter " << n << " non-negative elements:\n";

    for(int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> nums[i];

        if(nums[i] < 0) {
            cout << "Invalid input! Elements must be non-negative.\n";
            return 0;
        }
    }

    cout << "\nEnter the number of subarrays (k): ";
    cin >> k;

    if(k < 1 || k > n) {
        cout << "Invalid k! Enter a value between 1 and " << n << ".\n";
        return 0;
    }

    int result = obj.splitArray(nums, k);

    cout << "Minimum possible largest subarray sum: "
         << result << endl;

    return 0;
}