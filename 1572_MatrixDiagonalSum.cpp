#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {

        //full matrix traverse TC=(n^2) SC=(1)
        int n = mat.size();
        int sum=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j){
                    sum+=mat[i][j];
                }
                else if (i+j == n-1){
                    sum+= mat[i][j];
                }
            }
        }
        return sum;
        
        // //digonal wise TC=O(n) SCO(1)
        // int n = mat.size();
        // int sum=0;
        // ///digonsl
        // for(int i=0; i<n; i++){
        //     sum += mat[i][i];
        // }
        // //anti diagonal
        // for(int i=0; i<n; i++){
        //     if(i == n-1-i) continue;
        //     sum += mat[i][n-1-i];
        // }
        // return sum;
        
    }
};

int main() {

    int n;

    cout << "Enter the size of the square matrix: ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    cout << "Enter the elements of the matrix:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << "Element at position (" << i + 1 << ", " << j + 1 << "): ";
            cin >> mat[i][j];
        }
    }

    Solution s;

    int ans = s.diagonalSum(mat);

    cout << "\nThe sum of the diagonals is: " << ans << endl;

    return 0;
}