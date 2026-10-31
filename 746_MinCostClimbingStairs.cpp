
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {

    // TC = O(n) SC = O(1)
    int a = 0;
    int b = 0;

    for (int i = 2; i <= cost.size(); i++) {

        int curr = min( a + cost[i - 2], b + cost[i - 1] );

        a = b;
        b = curr;
    }

    return b;
}

int main() {

    int n;
    cout << "Enter number of steps: ";
    cin >> n;

    if (n < 2) {
        cout << "Please enter at least 2 steps.\n";
        return 0;
    }

    vector<int> cost(n);

    cout << "Enter the cost of each step:\n";

    for (int i = 0; i < n; i++) {
        cout << "Cost[" << i << "]: ";
        cin >> cost[i];
    }

    int result = minCostClimbingStairs(cost);

    cout << "\nMinimum cost to reach the top: "
         << result << endl;

    return 0;
}
