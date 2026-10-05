#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        // TC = O(n), SC = O(n)
        // vector<int> ans(nums.size());
        // int a = nums[0];
        // ans[0] = a;

        // for(int i = 1; i < nums.size(); i++) {
        //     a += nums[i];
        //     ans[i] = a;
        // }

        // return ans;


        // TC = O(n), SC = O(1)
        for(int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }

        return nums;
    }
};

int main() {

    Solution obj;

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " elements:" << endl;

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = obj.runningSum(nums);

    cout << "\nRunning Sum: ";

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}
