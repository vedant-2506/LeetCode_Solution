#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();

        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0] = height[0];
        for(int i = 1; i < n; i++)
            leftMax[i] = max(leftMax[i-1], height[i]);

        rightMax[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--)
            rightMax[i] = max(rightMax[i+1], height[i]);

        int water = 0;

        for(int i = 0; i < n; i++)
            water += min(leftMax[i], rightMax[i]) - height[i];

        return water;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the number of bars: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter the heights of the bars: ";
    for(int i = 0; i < n; i++)
        cin >> height[i];

    int trappedWater = sol.trap(height);
    cout << "Trapped water: " << trappedWater << endl;

    return 0;
}