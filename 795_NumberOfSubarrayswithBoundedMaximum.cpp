#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {

        // TC = O(n), SC = O(1)
        return countSubarrays(nums, right) - countSubarrays(nums, left - 1);
    }

    int countSubarrays(vector<int>& nums, int bound) {
        int count = 0 ,current = 0;

        for (int num : nums) {
            if (num <= bound) {
                current++;
            }
            else {
                current = 0;
            }
            count += current;
        }

        return count;
    }
};

int main() {
    Solution obj;
    int n, left, right;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid array size!\n";
        return 0;
    }

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter left bound: ";
    cin >> left;

    cout << "Enter right bound: ";
    cin >> right;

    if (left > right) {
        cout << "Invalid bounds!\n";
        return 0;
    }

    int result = obj.numSubarrayBoundedMax(nums, left, right);

    cout << "\nNumber of valid subarrays: " << result << endl;

    return 0;
}
