#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {

        // Multi-source BFS TC O(m*n) SC O(m*n)
        int rows = grid.size(), cols = grid[0].size();

        queue<pair<int, int>> q;

        vector<vector<bool>> V(
            rows,
            vector<bool>(cols, false)
        );

        // Push all land cells into queue
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){

                if(grid[r][c] == 1){
                    q.push({r, c});
                    V[r][c] = true;
                }
            }
        }

        if(q.empty() || q.size() == rows * cols){
            return -1;
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int distance = 1;

        while(!q.empty()){

            int sz = q.size();

            while(sz > 0){

                auto [r1, c1] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++){

                    int nr = r1 + dr[k];
                    int nc = c1 + dc[k];

                    if(nr >= 0 && nr < rows &&
                       nc >= 0 && nc < cols){

                        // Already visited
                        if(V[nr][nc] == true)
                            continue;

                        q.push({nr, nc});
                        V[nr][nc] = true;
                    }
                }

                sz--;
            }

            distance++;
        }

        return distance - 2;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {{1,0,1},{0,0,0},{1,0,1}};
    int result = solution.maxDistance(grid);
    cout << "Maximum distance from land: " << result << endl;
    return 0;
}