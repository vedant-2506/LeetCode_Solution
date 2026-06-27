#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // //1st put in 1 array and sort array TC:O(n+m) O(logn+m) SC= O(n+m)
        // vector<int>ans;

        // for(int i=0; i<m; i++){
        //     ans.push_back(nums1[i]);
        // }

        // for(int j=0; j<n; j++){
        //     ans.push_back(nums2[j]);
        // }

        // nums1= ans;

        // sort(nums1.begin() , nums1.end());

        //2nd aprroch TC = O(m+n) SC= O(m+n)

        int i=0,j=0;

        vector<int>ans;

        while(i<m && j<n){
            if(nums1[i] < nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            }
            else {
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while(i<m){
            ans.push_back(nums1[i]);
            i++;
        }

        while(j<n){
            ans.push_back(nums2[j]);
            j++;
        }

        nums1 = ans;
    }
};


int main() {

    int m, n;

    cout << "Enter number of valid elements in nums1 (m): ";
    cin >> m;

    cout << "Enter number of elements in nums2 (n): ";
    cin >> n;

    vector<int> nums1(m + n);
    vector<int> nums2(n);

    cout << "Enter " << m << " sorted elements of nums1: ";
    for(int i = 0; i < m; i++){
        cin >> nums1[i];
    }

    // Last n positions remain 0 (as per LeetCode)
    for(int i = m; i < m + n; i++){
        nums1[i] = 0;
    }

    cout << "Enter " << n << " sorted elements of nums2: ";
    for(int i = 0; i < n; i++){
        cin >> nums2[i];
    }

    Solution s;
    s.merge(nums1, m, nums2, n);

    cout << "Merged Array: ";
    for(int x : nums1){
        cout << x << " ";
    }
    cout << endl;
            
    return 0;
}