#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {

        int n = mat.size();
        int m = mat[0].size();

        if (n * m != r * c)
            return mat;

        vector<vector<int>> Ansmat(r, vector<int>(c));

        int a = 0, b = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                Ansmat[a][b] = mat[i][j];
                b++;
                if (b == c) {
                    a++;
                    b = 0;
                }
            }
        }

        return Ansmat;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {{1, 2}, {3, 4}};
    int r = 1, c = 4;

    vector<vector<int>> result = sol.matrixReshape(mat, r, c);

    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}