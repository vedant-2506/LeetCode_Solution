#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        int rows = points.size();

        priority_queue<
            pair<double, int>,
            vector<pair<double, int>>,
            greater<pair<double, int>>
        > minHeap;

        vector<vector<int>> ans;

        // Calculate distance and store in minHeap
        for(int i = 0; i < rows; i++){

            double dist = getDistance(points[i]);

            minHeap.push({dist, i});
        }

        // Get k closest points
        for(int j = 0; j < k; j++){

            // auto [d, pt] = minHeap.top();

            pair<double, int> temp = minHeap.top();

            ans.push_back(points[temp.second]);

            minHeap.pop();
        }

        return ans;
    }


    double getDistance(vector<int>& pt){

        double d = (pt[0] * pt[0]) +
                   (pt[1] * pt[1]);

        return sqrt(d);
    }
};


int main(){

    Solution sol;

    int n, k;

    cout << "Enter number of points: ";
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));

    cout << "Enter the coordinates (x y):" << endl;

    for(int i = 0; i < n; i++){

        cout << "Point " << i + 1 << ": ";

        cin >> points[i][0] >> points[i][1];
    }

    cout << "Enter number of closest points (k): ";
    cin >> k;

    vector<vector<int>> ans = sol.kClosest(points, k);

    cout << "\n" << k << " Closest Points:" << endl;

    for(auto point : ans){

        cout << "[" << point[0]
             << ", " << point[1]
             << "]" << endl;
    }

    return 0;
}



