#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        // Brute force
        // TC = O(n^2), SC = O(1)
        // int maxnum = 0;
        // for(int i = 0; i < nums.size(); i++){
        //     maxnum = max(maxnum, nums[i]);
        // }

        // for(int j = 1; j <= maxnum; j++){
        //     bool flag = false;

        //     for(int k = 0; k < nums.size(); k++){
        //         if(nums[k] == j){
        //             flag = true;
        //             break;
        //         }
        //     }

        //     if(flag == false)
        //         return j;
        // }

        // return maxnum + 1;


        // Using Cyclic Sort
        // TC = O(n), SC = O(1)

        int i = 0;

        while(i < nums.size()) {

            if(nums[i] <= 0 || nums[i] > nums.size()) {
                i++;
                continue;
            }

            if(nums[i] == nums[nums[i] - 1]) {
                i++;
                continue;
            }

            swap(nums[i], nums[nums[i] - 1]);
        }

        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] != j + 1) {
                return j + 1;
            }
        }

        return nums.size() + 1;
    }
};

int main() {

    Solution obj;

    int n;
    
    cout << "     First Missing Positive\n";
    

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " elements:\n";

    for(int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> nums[i];
    }

    int result = obj.firstMissingPositive(nums);

    
    cout << "First Missing Positive = " << result << endl;
    

    return 0;
}