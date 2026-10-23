#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        // //TC=O(n) SC=O(n)
        // unordered_map<int , int>un;
        // for(auto i : nums){
        //     un[i]++;
        // }
        // vector<int>ans;
        // for(auto [key ,value] : un){
        //     if(value >= 2){
        //         ans.push_back(key);
        //     }
        // }
        // return ans;

        // //TC=O(n^2) SC=O(1) Time Limit Exceeded 25 / 29 testcases passed
        // vector<int>ans;
        // for(int i=0; i<nums.size(); i++){
        //     for(int j=i+1; j<nums.size(); j++){
        //         if(nums[i] == nums[j]) ans.push_back(nums[i]);
        //     }
        // }
        // return ans;


        //TC=O(n) SC=O(1) LeetCode wants using cylic sort
         
        int i = 0;
        while (i < nums.size()) {
            int correctIndex = nums[i] - 1;

            if (nums[i] != nums[correctIndex]) {
                swap(nums[i], nums[correctIndex]);
            } else {
                i++;
            }
        }

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " elements (1 to " << n << "): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution solution;
    vector<int> duplicates = solution.findDuplicates(nums);

    cout << "Duplicate elements: ";
    for (int x : duplicates) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}