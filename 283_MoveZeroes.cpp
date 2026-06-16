#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    // //1st 2 pointer appoch TC=  SC=
    //   int j=0;
    //   for(int i=0; i<nums.size();  i++){
    //     if(nums[i] != 0){
    //         swap(nums[i] , nums[j]);
    //         j++;
    //     }
    //   }

    //2nd count zero aproch 
    int j=0, count=0;

    for(int i=0; i<nums.size(); i++){
        if(nums[i] != 0){
            nums[j++] =nums[i];
        }
        else{
            count++;
        }
    }

    while(count--){
        nums[j++] = 0;
    }
       
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sol.moveZeroes(nums);

    cout << "After moving zeroes: ";
    for(int num : nums) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}