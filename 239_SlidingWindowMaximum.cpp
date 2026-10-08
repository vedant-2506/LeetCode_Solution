#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        // TC = O(n)
        // SC = O(k)

        vector<int> ans;
        deque<int> q;

        for(int i = 0; i < nums.size(); i++) {

            // Remove smaller elements from back
            while(!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }

            // Remove elements outside current window
            while(!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }

            // Add current index
            q.push_back(i);

            // Window is ready
            if(i >= k - 1) {
                ans.push_back(nums[q.front()]);
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "\nEnter " << n << " elements:\n";

    for(int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> nums[i];
    }

    cout << "\nEnter window size k: ";
    cin >> k;

    if(k <= 0 || k > n) {
        cout << "\nInvalid window size!" << endl;
        return 0;
    }

    vector<int> result = obj.maxSlidingWindow(nums, k);
  
    cout << "[";

    for(int i = 0; i < result.size(); i++) {
        cout << result[i];

        if(i != result.size() - 1) {
            cout << ", ";
        }
    }

    cout << "]\n";



    return 0;
}