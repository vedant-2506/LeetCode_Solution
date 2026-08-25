#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        // TC = O(n^2), SC = O(1)
        int sz = nums.size();
        int maxpro = INT_MIN;

        for (int i = 0; i < sz; i++) {
            int pro = 1;

            for (int j = i; j < sz; j++) {
                pro *= nums[j];
                maxpro = max(maxpro, pro);
            }
        }

        return maxpro;
    }
};

int main() {
    Solution solution;

    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "\nEnter " << n << " elements:" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> nums[i];
    }

    int result = solution.maxProduct(nums);

    cout << "\nArray entered: ";

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    cout << "\n\nMaximum product of a subarray: " << result << endl;

    return 0;
}