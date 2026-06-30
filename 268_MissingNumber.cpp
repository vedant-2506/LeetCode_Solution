#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<cmath>
#include<stack>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        // // 1st sorting approch TC = O(nlogn) SC = O(1) 

        // sort(nums.begin() , nums.end());
        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i] != i) return i;
        // }
        // return nums.size();

         //2nd sol: using hash table TC O(n) , SC=O(n)

        unordered_map<int ,int>un;
        for(int i=0; i<nums.size(); i++){
            un[ nums[i] ] = 1;
        }
        for(int j=0; j<nums.size(); j++){
            if( un.find( j ) == un.end()) return j;
        }
        return nums.size();
        
        // // 3rd sum of n number approch n*(n+1)/2 
        // //TC = O(n)  SC = O(1)

        // int n = nums.size();
        // int expect_sum = n*(n+1)/2;
        // int actual_sum = 0;
        // for(int i=0; i<n; i++){
        //     actual_sum += nums[i];
        // }
        // return expect_sum - actual_sum;
    }
};

int main() {

    Solution s;

    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = s.missingNumber(nums);

    cout << "Missing Number = " << ans << endl;

    return 0;
}