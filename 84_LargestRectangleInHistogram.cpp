#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        // //TC=O(n^2) SC=O(1)
        // int sz = heights.size(), maxArea = 0;
        // for(int i = 0; i < sz; i++) {
        //     int R = i, L = i;

        //     while(L >= 0 && heights[L] >= heights[i]) {
        //         L--;
        //     }

        //     while(R < sz && heights[R] >= heights[i]) {
        //         R++;
        //     }

        //     int area = heights[i] * (R - L - 1);
        //     maxArea = max(maxArea, area);
        // }

        // return maxArea;


        //TC=O(n) SC=O(n)
       
        int sz = heights.size();
        int maxArea = 0;
        stack<int> stk;

        for(int i = 0; i <= sz; i++) {
            int h = (i == sz) ? 0 : heights[i];

            while(!stk.empty() && heights[stk.top()] >= h) {
                int ht = heights[stk.top()];
                stk.pop();

                int width = stk.empty() ? i : i - stk.top() - 1;

                int area = ht * width;
                maxArea = max(maxArea, area);
            }
            
            if(i < sz) {
                stk.push(i);
            }
        }

        return maxArea;
    }
};

int main() {
    Solution obj;

    int n;

    cout << "Enter the number of histogram bars: ";
    cin >> n;

    if(n < 0) {
        cout << "Invalid number of bars!\n";
        return 0;
    }

    vector<int> heights(n);

    cout << "Enter the heights of the bars:\n";

    for(int i = 0; i < n; i++) {
        cin >> heights[i];

        if(heights[i] < 0) {
            cout << "Heights cannot be negative!\n";
            return 0;
        }
    }

    int result = obj.largestRectangleArea(heights);

    cout << "Largest rectangle area: " << result << endl;

    return 0;
}