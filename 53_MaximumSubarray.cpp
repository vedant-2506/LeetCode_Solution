#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // // brute force TCO(n^2) SC=O(1) but algo give Time Limit Exceede 
        // if(nums.size() == 1) return nums[0];
        // int maxSum=INT_MIN;
        // for(int i=0; i<nums.size(); i++){
        //     int sum=0;
        //     for(int j=i; j<nums.size(); j++){
        //         sum+=nums[j];
        //         maxSum = max(sum, maxSum);
        //     }
        // } 
        // return maxSum;

        //Kadane's Algorithm TC=(n) SC=O(1)
        int sz=nums.size();
        if(sz==1) return nums[0];
        int sum = nums[0] , maxSum = nums[0] ;
        for(int i=1; i<sz; i++){
            sum = max(nums[i] , sum+nums[i]);
            maxSum = max(maxSum , sum);
        }
        return maxSum;
    }
};

int main() {

    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " integer elements:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> nums[i];
    }

    Solution s;

    int ans = s.maxSubArray(nums);

    cout << "\nMaximum Subarray Sum: " << ans << endl;

    return 0;
}