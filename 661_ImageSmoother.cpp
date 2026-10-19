#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {

        // TC = O(m * n), SC = O(m * n)
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                int count = 0;

                for (int r = i - 1; r <= i + 1; r++) {
                    for (int c = j - 1; c <= j + 1; c++) {

                        if (r >= 0 && r < m && c >= 0 && c < n) {

                            sum += img[r][c];
                            count++;
                        }
                    }
                }
                ans[i][j] = sum / count;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;

    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    if (m <= 0 || n <= 0) {
        cout << "Invalid matrix dimensions!\n";
        return 0;
    }

    vector<vector<int>> img(m, vector<int>(n));

    cout << "Enter image pixel values:\n";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> img[i][j];
        }
    }

    vector<vector<int>> result = obj.imageSmoother(img);

    cout << "\nSmoothed image:\n";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
