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

int main(){
    Solution s;
    vector<int>nums = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = s.maxSubArray(nums);
    cout<<ans<<endl; 
    return 0;
}