#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // // Brute force
        // // TC = O(2^n * n)
        // // SC = O(2^n * n)
        // vector<vector<int>> ans;
        // set<vector<int>> ansSet;
        // vector<int> curr;

        // Backtrack(0, curr, nums, ansSet);

        // for(auto e : ansSet){
        //     ans.push_back(e);
        // }

        // return ans;


        // Optimal solution
        // TC = O(2^n * n)
        // SC = O(n) auxiliary space
        vector<vector<int>> ans;
        vector<int> curr;

        sort(nums.begin(), nums.end());

        backtrack_opti(0, curr, nums, ans);

        return ans;
    }


    // Brute force
    // Generate all subsets and use set to remove duplicates
    // TC = O(2^n * n)
    // SC = O(2^n * n)

    void Backtrack(int idx,
                   vector<int>& curr,
                   vector<int>& nums,
                   set<vector<int>>& ansSet){

        if(idx == nums.size()){
            vector<int> temp(curr);

            sort(temp.begin(), temp.end());

            ansSet.insert(temp);

            return;
        }

        // Include
        curr.push_back(nums[idx]);

        Backtrack(idx + 1, curr, nums, ansSet);

        // Exclude
        curr.pop_back();

        Backtrack(idx + 1, curr, nums, ansSet);
    }


    // Optimal solution
    // Skip duplicate elements during backtracking
    // TC = O(2^n * n)
    // SC = O(n) auxiliary recursion space

    void backtrack_opti(int idx,
                        vector<int>& curr,
                        vector<int>& nums,
                        vector<vector<int>>& ans){

        if(idx == nums.size()){
            ans.push_back(curr);
            return;
        }

        // Include
        curr.push_back(nums[idx]);

        backtrack_opti(idx + 1, curr, nums, ans);

        // Remove included element
        curr.pop_back();

        // Skip duplicate elements
        while(idx < nums.size() - 1 &&
              nums[idx] == nums[idx + 1]){
            idx++;
        }

        // Exclude
        backtrack_opti(idx + 1, curr, nums, ans);
    }
};


int main(){

    Solution sol;

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " elements: ";

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector<vector<int>> result = sol.subsetsWithDup(nums);

    cout << "\nUnique subsets:\n";

    for(auto subset : result){

        cout << "[ ";

        for(int x : subset){
            cout << x << " ";
        }

        cout << "]" << endl;
    }

    cout << "\nTotal unique subsets: "
         << result.size() << endl;

    return 0;
}