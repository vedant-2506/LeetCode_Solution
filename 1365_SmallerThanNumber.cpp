#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // // using 2 loop TC=O(n^2) SC=O(n)
        // int sz = nums.size();
        // vector<int>ans(sz);
        // for(int i=0; i<sz; i++){
        //     int count=0;
        //     for(int j=0; j<sz; j++){
        //         if(i!=j && nums[i]>nums[j]) 
        //            count++;
        //     }
        //     ans[i] = count;
        // }
        // return ans;

        //soting+hashmap TC=O(nlogn) SC=O(n)
        int sz=nums.size();
        vector<int>sorted=nums;
        sort(sorted.begin(),sorted.end());
        unordered_map<int ,int>un;
        for(int i=0; i<sz; i++){
            if(un.find( sorted[i] ) == un.end()){
                un[sorted[i]]=i;
            } 
        }
        vector<int>ans(sz);
        for(int j=0; j<sz; j++){
            ans[j]= un[ nums[j] ];
        }
        return ans;
    }
};


int main() {

    Solution sol;
    int n;

    cout << "\nEnter the size of the array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " integers:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = sol.smallerNumbersThanCurrent(nums);

    cout << "\nInput Array : ";
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    cout << "\n\nResult (Number of elements smaller than each element):" << endl;
    cout << "[ ";
    for(int i = 0; i < n; i++) {
        cout << result[i];
        if(i != n - 1)
            cout << ", ";
    }
    cout << " ]" << endl;

    return 0;
}