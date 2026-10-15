
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {

        // TC = O(n), SC = O(1)
        int sz = nums.size();

        if (sz == 0) return 0;
        if (sz == 1) return nums[0];

        // Exclude the last house
        int first = HouseRobber(nums, 0, sz - 2);

        // Exclude the first house
        int second = HouseRobber(nums, 1, sz - 1);

        return max(first, second);
    }

    int HouseRobber(vector<int>& nums, int start, int end) {

        int prev1 = 0, prev2 = 0;

        for (int i = start; i <= end; i++) {

            // Choose the current house or skip it
            int ans = max(prev1, nums[i] + prev2);

            prev2 = prev1;
            prev1 = ans;
        }

        return prev1;
    }
};

int main() {

    Solution obj;
    int n;
    
    cout << "Enter number of houses: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid number of houses!\n";
        return 0;
    }

    vector<int> nums(n);

    cout << "Enter money in each house:\n";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = obj.rob(nums);

    cout << "\nMaximum money that can be robbed: "
         << result << endl;

    return 0;
}
