#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        //1st using 2pointer TC = O(n^2) SC= O(1)
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            int count =0;
            for(int j=0; j<n; j++){
                if(nums[i] == nums[j]) count++;
            }
            if(count > n/2) return nums[i];
        }

        return -1;
        
        // //2nd approch hash table TC=O(n) SC=O(n)
        // unordered_map<int , int>un;
        // int n = nums.size();

        // for(int i=0; i<n; i++){
        //     un[nums[i]]++;
        // }

        // for(int j=0; j<n;j++){
        //     if(un[ nums[j] ] > n/2){
        //         return nums[j];
        //     }
        // }

        // return -1;
    }
};

int main() {

    Solution s;

    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int ans = s.majorityElement(nums);

    cout << "Majority Element: " << ans << endl;

    return 0;
}
