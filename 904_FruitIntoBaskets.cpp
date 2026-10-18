#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        // TC = O(n), SC = O(1)
        int sz = fruits.size();
        int left = 0, maxWindow = 0;

        unordered_map<int, int> basket;

        for (int right = 0; right < sz; right++) {
            basket[fruits[right]]++;

            while (basket.size() > 2) {
                basket[fruits[left]]--;

                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
            }
            maxWindow = max(maxWindow, right - left + 1);
        }

        return maxWindow;
    }
};

int main() {
    Solution obj;
    int n;

    cout << "Enter number of trees: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid number of trees!\n";
        return 0;
    }

    vector<int> fruits(n);

    cout << "Enter fruit types for each tree:\n";

    for (int i = 0; i < n; i++) {
        cin >> fruits[i];
    }

    int result = obj.totalFruit(fruits);

    cout << "\nMaximum fruits that can be collected: "
         << result << endl;

    return 0;
}
