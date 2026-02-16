#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size() ,
            m = matrix[0].size();
                   
            vector<int>col(m,0);
            vector<int>row(n,0);

            //check where is zero
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(matrix[i][j] == 0){
                        col[j] =1;
                        row[i] =1;
                    }
                }
            }

            //set zero
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(row[i] == 1 || col[j] == 1 ){
                            matrix[i][j] =0;
                        }
                }
            }   
    }
};

int main(){
    Solution sol;
    
    // Test case 1: Matrix with zero at [0][0]
    vector<vector<int>> matrix1 = {{1,1,1},{1,0,1},{1,1,1}};
    sol.setZeroes(matrix1);
    cout << "Test case 1 result:\n";
    for(auto& row : matrix1) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    
    
    
    return 0;
} 
