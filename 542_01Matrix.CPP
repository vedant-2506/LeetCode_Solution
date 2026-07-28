#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> dist(rows, vector<int>(cols, -1));
        queue<pair<int,int>> q;

        // Push all 0's into the queue
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(mat[r][c] == 0){
                    q.push({r, c});
                    dist[r][c] = 0;
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()){

            auto [r, c] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++){

                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 && nr < rows &&
                   nc >= 0 && nc < cols &&
                   dist[nr][nc] == -1){

                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return dist;
    }
};

int main() {

    Solution sol;

    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> cols;

    vector<vector<int>> mat(rows, vector<int>(cols));

    cout << "\nEnter the matrix values (only 0 and 1):\n";
    cout << "0 = Cell containing 0\n";
    cout << "1 = Cell containing 1\n\n";

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> result = sol.updateMatrix(mat);

    cout << "\nDistance Matrix:\n";

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}