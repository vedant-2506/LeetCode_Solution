#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int sz = nums.size();
        k = k % sz;
        vector<int>ans(sz);

        int j=0,i=(sz-k);
        while(i<sz){
            ans[j] = nums[i];
            i++;
            j++;
        }

        int l = (sz-k-1);
        i=0;
        while(i<=l){
            ans[j] = nums[i];
            i++;
            j++;
        }

        i=0;
        while (i < sz){
            nums[i] = ans[i];
            i++;
        }
    }
};

int main(){
    Solution s;
    vector<int>nums = {1,2,3,4,5,6,7};
    int k = 3;
    s.rotate(nums,k);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}