#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        
        // DP TC = O(n), SC = O(n)
        int n = nums.size();
        
        if (n == 1) return nums[0];

        vector<int> P(n + 1, 0);
        
        P[1] = nums[0];

        for (int i = 1; i < n; i++) {
            P[i + 1] = max(P[i - 1] + nums[i], P[i]);
        }

        return P[n];
    }
};

int main() {

    Solution sol;

    int n;

    cout << "Enter the number of houses: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the money in each house:" << endl;

    for (int i = 0; i < n; i++) {
        cout << "House " << i + 1 << ": ";
        cin >> nums[i];
    }

    int result = sol.rob(nums);

    cout << "\nMaximum money that can be robbed: "
         << result << endl;

    return 0;
}
