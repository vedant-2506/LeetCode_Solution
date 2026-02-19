#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int sz = nums.size();
        for(int i = 0; i < sz; i++) {
            if(nums[i] >= target)
                return i;
        }
        return sz;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1,3,5,6};
    int target = 5;

    cout << obj.searchInsert(nums, target);
    return 0;
}
