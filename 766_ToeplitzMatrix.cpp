#include <vector>
#include <iostream>
// #include <algorithm>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows=matrix.size(),
            cols=matrix[0].size();

        for(int i=0;i<rows-1;i++){
            for(int j=0;j<cols-1;j++){
                if(matrix[i][j] != matrix[i+1][j+1]){
                    return false;
                }
            }
        }

        return true;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {{1,2,3,4},
                                  {5,1,2,3},
                                  {9,5,1,2}};
    cout << s.isToeplitzMatrix(matrix) << endl; // Output: 1 (true)
    return 0;
}