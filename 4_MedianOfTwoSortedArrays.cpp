#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // TC = O(log(min(m, n)))
        // SC = O(1)

        if(nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int lo = 0;
        int high = m;
        int hlf = (m + n + 1) / 2;

        while(lo <= high) {

            int cutX = (lo + high) / 2;
            int cutY = hlf - cutX;

            int LX = (cutX == 0) ? INT_MIN : nums1[cutX - 1];
            int RX = (cutX == m) ? INT_MAX : nums1[cutX];

            int LY = (cutY == 0) ? INT_MIN : nums2[cutY - 1];
            int RY = (cutY == n) ? INT_MAX : nums2[cutY];

            if(LX <= RY && LY <= RX) {

                if((m + n) % 2 == 1) {
                    return max(LX, LY);
                }
                else {
                    return ((double)max(LX, LY) + min(RX, RY)) / 2;
                }
            }
            else if(LX > RY) {
                high = cutX - 1;
            }
            else {
                lo = cutX + 1;
            }
        }

        return 0;
    }
};

int main() {

    Solution obj;

    int m, n;

    cout << "Enter the size of the first sorted array: ";
    cin >> m;

    vector<int> nums1(m);

    cout << "\nEnter " << m << " elements in sorted order:\n";

    for(int i = 0; i < m; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> nums1[i];
    }

    cout << "\nEnter the size of the second sorted array: ";
    cin >> n;

    vector<int> nums2(n);

    cout << "\nEnter " << n << " elements in sorted order:\n";

    for(int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> nums2[i];
    }

    if(m + n == 0) {
        cout << "\nError: Both arrays cannot be empty.\n";
        return 0;
    }

    double median = obj.findMedianSortedArrays(nums1, nums2);

    cout << "Median = " << median << endl;
   
    return 0;
}