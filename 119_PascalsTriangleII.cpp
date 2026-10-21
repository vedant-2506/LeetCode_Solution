#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {

        // TC = O(rowIndex^2), SC = O(rowIndex^2)

        vector<vector<int>> Triangle;

        Triangle.push_back({1});
        if (rowIndex == 0) return Triangle[0];

        Triangle.push_back({1, 1});
        if (rowIndex == 1) return Triangle[1];

        for (int r = 2; r <= rowIndex; r++) {
            vector<int> miniTri;
            miniTri.push_back(1);

            for (int i = 0; i < Triangle[r - 1].size() - 1; i++) {
                int a = Triangle[r - 1][i];
                int b = Triangle[r - 1][i + 1];

                miniTri.push_back(a + b);
            }

            miniTri.push_back(1);
            Triangle.push_back(miniTri);
        }

        return Triangle[rowIndex];
    }
};

int main() {
    int rowIndex;

    cout << "Enter the row index (starting from 0): ";
    cin >> rowIndex;

    if (rowIndex < 0) {
        cout << "Please enter a non-negative row index.\n";
        return 1;
    }

    Solution solution;
    vector<int> result = solution.getRow(rowIndex);

    cout << "\nRow " << rowIndex << ": ";
    for (int value : result) {
        cout << value << " ";
    }
    cout << '\n';

    return 0;
}
