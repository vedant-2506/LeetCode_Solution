
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        //2nd using 1 loop TC=O(n) Sc=O(1)
        int count=0 , maxC=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] ==1){
            count++;
            maxC = max(maxC , count);
            }
            else
              count=0;
        }
        return maxC;
        
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