
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        // TC = O(n log n + k log n)  SC = O(n)

        int sz = profits.size();
        vector<pair<int, int>> project(sz);

        for(int i = 0; i < sz; i++) {
            project[i] = {capital[i], profits[i]};
        }

        sort(project.begin(), project.end());

        priority_queue<int> maxHeap;

        int p = 0;

        for(int i = 0; i < k; i++) {

            while(p < sz && w >= project[p].first) {
                maxHeap.push(project[p].second);
                p++;
            }

            if(maxHeap.empty()) {
                break;
            }

            w += maxHeap.top();

            maxHeap.pop();
        }

        return w;
    }
};

int main() {
    Solution obj;

    int k, w, n;

    cout << "Enter the maximum number of projects (k): ";
    cin >> k;

    cout << "Enter the initial capital (w): ";
    cin >> w;

    cout << "Enter the number of available projects (n): ";
    cin >> n;

    if(k < 0 || w < 0 || n < 0) {
        cout << "Invalid input! Values cannot be negative.\n";
        return 0;
    }

    vector<int> profits(n);
    vector<int> capital(n);

    // Input project profits
    cout << "\nEnter the profits of " << n << " projects:\n";
    for(int i = 0; i < n; i++) {
        cin >> profits[i];

        if(profits[i] < 0) {
            cout << "Invalid input! Profits cannot be negative.\n";
            return 0;
        }
    }

    cout << "\nEnter the required capital for " << n << " projects:\n";
    for(int i = 0; i < n; i++) {
        cin >> capital[i];

        if(capital[i] < 0) {
            cout << "Invalid input! Capital requirements cannot be negative.\n";
            return 0;
        }
    }

    int result = obj.findMaximizedCapital(k, w, profits, capital);
    cout << "Maximum capital: " << result << endl;
   
    return 0;
}
