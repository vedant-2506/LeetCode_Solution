#include<vector>
#include<climits>
#include<iostream>

using namespace std;
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        // //using for loop TC=O(n) SC=O(n)
        // int sz=nums.size();
        // vector<int>ans(sz);
        // int ans_i=0;
        // for(int i=0; i<n ;i++){
        //     ans[ans_i]   = nums[i];
        //     ans[ans_i+1] = nums[i+n];
        //     ans_i +=2;
        // }
        // return ans;

        //using while loop TC=O(n) SC=O(n)
        int sz=nums.size();
        int i=0;
        vector<int>ans(sz);
        while(i<n){
            ans[2*i]  =nums[i];
            ans[2*i+1]=nums[n+i];
            i++;
        }
        return ans;
        
    }
};


int main() {

    Solution obj;

    int n;

    cout << "Enter the value of n (half of the array size): ";
    cin >> n;

    vector<int> nums(2 * n);

    cout << "Enter " << 2 * n << " elements in the format:" << endl;
    cout << "x1 x2 ... xn y1 y2 ... yn" << endl;
    cout << "Example: 2 5 1 3 4 7" << endl;
    cout << "\nEnter the elements: ";

    for(int i = 0; i < 2 * n; i++) {
        cin >> nums[i];
    }

    vector<int> ans = obj.shuffle(nums, n);

    cout << "\nOriginal Array : ";
    for(int i = 0; i < 2 * n; i++) {
        cout << nums[i] << " ";
    }

    cout << "\nShuffled Array : ";
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}