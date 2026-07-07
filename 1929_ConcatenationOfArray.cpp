#include<vector>
#include<climits>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {

        //using 2 diffrent loop TC=(n) SC=O(1)
        int sz=nums.size();
        vector<int>ans(sz*2);
        for(int i=0; i<sz; i++){
            ans[i] = nums[i];
        }
        for(int i=0; i<sz; i++){
            ans[sz+i] = nums[i];
        }
        return ans;

        // //using single loop TC=(n) SC=O(1)
        // int sz = nums.size();
        // vector<int>ans(sz*2);
        // for(int i=0; i<sz; i++){
        //     ans[i] = nums[i];
        //     ans[sz+i] = nums[i];
        // }
        // return ans;
    }
};

int main() {

    Solution obj;

    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "\nEnter " << n << " integer elements:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> nums[i];
    }

    vector<int> ans = obj.getConcatenation(nums);

    cout << "\nOriginal Array      : ";
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    cout << "\nConcatenated Array  : ";
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << endl;
    cout << "\nThank you!" << endl;

    return 0;
}