#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       
        // // k=k%n TC = O(n+k) SC = O(n)
        // int sz = nums.size();
        // k = k%sz;
        // vector<int>ans(sz);
        // int i= 0 , j= sz-k;
        // while(j<sz){
        //     ans[i] = nums[j];
        //     i++;
        //     j++;
        // }       
        // int l = sz-k;
        // j=0;
        // while(j<l){
        //     ans[i] = nums[j];
        //     i++;
        //     j++;
        // }
        // i=0;
        // while(i<sz){
        //     nums[i] = ans[i];
        //     i++;
        // }

        // 2nd approch k=k%n reverse k elemnt reverse 
        // TC = O(n)  SC = O(1)

        int sz = nums.size();
        k=k%sz;
        int i =0 , j=sz-k ;

        reverse(nums.begin() , nums.end());
        reverse(nums.begin() , nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};
int main() {

    Solution s;

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cout << "Enter the value of k (number of rotations): ";
    cin >> k;

    s.rotate(nums, k);

    cout << "\nArray after rotating by " << k << " positions:\n";
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}