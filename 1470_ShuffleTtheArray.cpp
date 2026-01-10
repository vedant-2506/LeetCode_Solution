#include<vector>
#include<climits>
#include<iostream>
using namespace std;



class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        int sz=nums.size();

        vector<int>ans(sz);

        
        int ans_i=0;
        for(int i=0; i<n ;i++){

            ans[ans_i]   = nums[i];
            ans[ans_i+1] = nums[i+n];

            ans_i +=2;
        }

        return ans;
    }
};


int main(){
    int n=3;

    vector<int> nums = {2, 5, 1, 3, 4, 7};

    Solution obj;
    vector<int> ans = obj.shuffle(nums, n);
    cout << "Answer array is : ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }


    return 0;


}