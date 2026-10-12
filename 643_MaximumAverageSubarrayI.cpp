
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        // Brute Force Approach TC = O(n * k), SC = O(1)

        /*
        double maxAvg = INT_MIN, avg = 0;

        for(int i = 0; i <= nums.size() - k; i++) {
            double sum = 0;

            for(int j = i; j < i + k; j++) {
                sum += nums[j];
            }

            avg = sum / k;
            maxAvg = max(maxAvg, avg);
        }

        return maxAvg;
        */

        // Optimized Sliding Window Approach TC = O(n), SC = O(1)

        double sum = 0;
        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }

        double maxSum = sum;

        for(int j = k; j < nums.size(); j++) {
            sum = sum - nums[j - k] + nums[j];

            maxSum = max(maxSum, sum);
        }

        return maxSum / k;
    }
};

int main() {
    Solution obj;

    int n, k;

    // Input the array size
    cout << "Enter the number of elements: ";
    cin >> n;

    // Validate array size
    if(n <= 0) {
        cout << "Invalid array size!\n";
        return 0;
    }

    vector<int> nums(n);

    // Input array elements
    cout << "Enter " << n << " elements:\n";

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Input the window size
    cout << "Enter the window size (k): ";
    cin >> k;

    // Validate k
    if(k < 1 || k > n) {
        cout << "Invalid k! Enter a value between 1 and "
             << n << ".\n";
        return 0;
    }

    // Call the function
    double result = obj.findMaxAverage(nums, k);

    // Display the result
    cout << "Maximum average: " << result << endl;
    

    return 0;
}
