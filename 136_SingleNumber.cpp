#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        // Using unordered_map
        // TC = O(n), SC = O(n)
        /*
        if (nums.size() == 1) return nums[0];

        unordered_map<int, int> un;

        for (int i = 0; i < nums.size(); i++) {
            un[nums[i]]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (un[nums[i]] == 1) return nums[i];
        }

        return -1;
        */

        // Using XOR
        // TC = O(n), SC = O(1)
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            ans = ans ^ nums[i];
        }

        return ans;
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

    cout << "\nArray: ";

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    int result = solution.singleNumber(nums);

    cout << "\n\nThe single number is: " << result << endl;

    return 0;
}