
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        // Sorting method  TC = O(n log n), SC = O(n) 
        /*
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            int a = nums[i] * nums[i];
            ans.push_back(a);
        }

        sort(ans.begin(), ans.end());
        return ans;
        */

        // Two-pointer method TC = O(n), SC = O(1) 
        int sz = nums.size();
        vector<int> ans(sz);
        int i = 0, j = sz - 1;
        int k = sz - 1;

        while(i <= j) {  // FIX: use <= to process the last element
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];

            if(a > b) {
                ans[k] = a;
                i++;
            }
            else {
                ans[k] = b;
                j--;
            }

            k--;
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    if(n < 0) {
        cout << "Invalid array size!\n";
        return 0;
    }

    vector<int> nums(n);

    cout << "Enter " << n
         << " elements in sorted order:\n";

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> ans = obj.sortedSquares(nums);

    cout << "\nSorted squares: ";
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}
