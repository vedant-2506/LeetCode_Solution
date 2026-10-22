#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        // TC = O(n) average, SC = O(n)
        unordered_map<int, int> un;
        for (auto i : nums) {
            un[i]++;
        }
    
        for (auto j : nums) {
            if (un[j] >= 2) return true;
        }
        return false;
    }
};

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (n < 0) {
        cout << "Number of elements cannot be negative.\n";
        return 1;
    }

    vector<int> nums(n);

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution solution;

    bool result = solution.containsDuplicate(nums);

    if (result) {
        cout << "Duplicate elements found.\n";
    } else {
        cout << "No duplicate elements found.\n";
    }

    return 0;
}