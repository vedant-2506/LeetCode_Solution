
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, cnt = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                cnt++;
            }
            else{
                cnt = 0;
            }
            ans = max(ans, cnt);  // ✅ max() instead of fmax()
        }

        return ans;
    }
};

int main(){
    int numsSize;
    cout << "Enter size of array: ";
    cin >> numsSize;

    vector<int> nums(numsSize);  // ✅ vector instead of malloc

    cout << "Enter " << numsSize << " elements (0s and 1s only):" << endl;
    for(int i = 0; i < numsSize; i++){
        cin >> nums[i];

        if(nums[i] != 0 && nums[i] != 1){
            cout << "Invalid input. Please enter only 0s and 1s." << endl;
            return -1;
        }
    }

    Solution s;
    int result = s.findMaxConsecutiveOnes(nums);
    cout << "Max consecutive ones: " << result << endl;

    return 0;
}