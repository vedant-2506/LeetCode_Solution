#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // //using sort function TC=O(nlogn) SC=O(1)
        // if(k > nums.size()) return -1;
        // sort(nums.begin() , nums.end());
        // return nums[ nums.size()-k ];

           // using heap TC=O(n + klogn) SC=O(n)
           if(k > nums.size()) return -1;
           priority_queue<int>heap(nums.begin() , nums.end());
           for(int i=1; i<k; i++){
            heap.pop();
           }
           return heap.top();
        
    }
};

int main() {

    int n, k;

    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " integer elements:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> nums[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    Solution s;

    int ans = s.findKthLargest(nums, k);

    if(ans != -1) {
        cout << "\nThe " << k << "-th largest element is: " << ans << endl;
    } else {
        cout << "\nInvalid value of k." << endl;
    }

    return 0;
}