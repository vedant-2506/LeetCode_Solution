#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> curr;

        Backtrack(0, curr, nums, ans);

        return ans;
    }

    void Backtrack(int idx,
                   vector<int>& curr,
                   vector<int>& nums,
                   vector<vector<int>>& ans) {

        // Base case
        if(idx == nums.size()) {
            ans.push_back(curr);
            return;
        }

        // Include
        curr.push_back(nums[idx]);
        Backtrack(idx + 1, curr, nums, ans);

        // Exclude
        curr.pop_back();
        Backtrack(idx + 1, curr, nums, ans);
    }
};

int main() {

    Solution sol;

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Generate subsets
    vector<vector<int>> result = sol.subsets(nums);

    // Display result
    cout << "\nAll possible subsets:\n";

    for(const auto& subset : result) {

        cout << "[ ";

        for(int x : subset) {
            cout << x << " ";
        }

        cout << "]" << endl;
    }

    cout << "\nTotal subsets: " << result.size() << endl;

    return 0;
}