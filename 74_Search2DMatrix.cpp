#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // TC = O(log(rows * cols)), SC = O(1)
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int rows = matrix.size();
        int cols = matrix[0].size();

        int lo = 0, hi = (rows * cols) - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
           
            int r = mid / cols;
            int c = mid % cols;

            if (matrix[r][c] == target) return true;

            else if (matrix[r][c] > target){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }

        return false;
    }
};

int main() {
    Solution obj;

    int rows, cols, target;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    if (rows <= 0 || cols <= 0) {
        cout << "Invalid matrix dimensions!\n";
        return 0;
    }

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter matrix elements in sorted order:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Enter target: ";
    cin >> target;

    bool result = obj.searchMatrix(matrix, target);

    if (result)
        cout << "Target found in the matrix.\n";
    else
        cout << "Target not found in the matrix.\n";

    return 0;
}
