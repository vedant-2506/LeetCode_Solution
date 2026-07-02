#include <iostream>
#include <vector>
#include<algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        //1st approch sorting TC =O(nlogn) SC=O(1)
        sort(nums.begin(), nums.end());
        vector<int>ans;
        int exp =1;
        for(int i=0; i<nums.size(); i++){
            while(exp < nums[i]){
                ans.push_back(exp);
                exp++;
            }
            if(exp == nums[i]) exp++;
        }

        while(exp <= nums.size()){
            ans.push_back(exp);
            exp++;
        }
        
        return ans;

        // //2nd Hash table  TC = O(n) Sc=O(n)
        // vector<int>ans;
        // unordered_map<int , int>un;
        // for(int i=0; i<nums.size();i++){
        //     un[ nums[i] ] = 1;
        // }
        // for(int j=1; j<= nums.size(); j++){
        //     if(un.find(j) == un.end()) ans.push_back(j);
        // }
        // return ans;
        
    }
};

int main() {

    Solution sol;

    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " elements (values should be between 1 and " << n << "):" << endl;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = sol.findDisappearedNumbers(nums);

    cout << "\nDisappeared Numbers: ";

    if (result.empty()) {
        cout << "No disappeared numbers.";
    } else {
        for (int num : result) {
            cout << num << " ";
        }
    }

    cout << endl;

    return 0;
}