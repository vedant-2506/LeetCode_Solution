#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        // //Time Limit Exceeded
        // //bfs 
        // int rows = heights.size();
        // int cols = heights[0].size();
        // vector<vector<int>> ans;
        // for(int r = 0; r < rows; r++){
        //     for(int c = 0; c < cols; c++){

        //         if(bothReach(heights, r, c)){
        //             ans.push_back({r, c});
        //         }
        //     }
        // }
        // return ans;


        //2nd approch  TC=O(m*n)  SC=O(m*n)
        //Reverse BFS
          int rows = heights.size();
        int cols = heights[0].size();

        // Cells reachable  Pacific 
        vector<vector<bool>> pacific(
            rows, vector<bool>(cols, false)
        );

        // Cells reachable  Atlantic 
        vector<vector<bool>> atlantic(
            rows, vector<bool>(cols, false)
        );

        queue<pair<int,int>> pacificQueue;
        queue<pair<int,int>> atlanticQueue;

        // Pacific Ocean
        // Top row + Left column
        for(int r = 0; r < rows; r++) {

            pacific[r][0] = true;
            pacificQueue.push({r, 0});
        }

        for(int c = 0; c < cols; c++) {

            if(!pacific[0][c]) {

                pacific[0][c] = true;
                pacificQueue.push({0, c});
            }
        }

        // Atlantic Ocean
        // Bottom row + Right column
        for(int r = 0; r < rows; r++) {

            atlantic[r][cols - 1] = true;
            atlanticQueue.push({r, cols - 1});
        }

        for(int c = 0; c < cols; c++) {

            if(!atlantic[rows - 1][c]) {

                atlantic[rows - 1][c] = true;
                atlanticQueue.push({rows - 1, c});
            }
        }
        // BFS from Pacific
        bfs(heights, pacificQueue, pacific);
        // BFS from Atlantic
        bfs(heights, atlanticQueue, atlantic);

        // Find cells reachable from both
        vector<vector<int>> ans;

        for(int r = 0; r < rows; r++) {

            for(int c = 0; c < cols; c++) {

                if(pacific[r][c] && atlantic[r][c]) {

                    ans.push_back({r, c});
                }
            }
        }

        return ans;
    }


    //Time Limit Exceeded
    //bfs 
    bool bothReach(vector<vector<int>>& heights, int r, int c){

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> V(rows, vector<bool>(cols, false));

        queue<pair<int,int>> q;

        q.push({r, c});
        V[r][c] = true;

        bool pacific = false;
        bool atlantic = false;

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!q.empty()){

            auto [r1,c1] = q.front();
            q.pop();

            if(r1 == 0 || c1 == 0)
                pacific = true;

            if(r1 == rows-1 || c1 == cols-1)
                atlantic = true;

            if(pacific && atlantic)
                return true;

            for(int k = 0; k < 4; k++){

                int nr = r1 + dr[k];
                int nc = c1 + dc[k];

                if(nr >= 0 && nr < rows &&
                   nc >= 0 && nc < cols &&
                   !V[nr][nc] &&
                   heights[nr][nc] <= heights[r1][c1]){

                    q.push({nr,nc});
                    V[nr][nc] = true;
                }
            }
        }

        return false;
    }



     //Reverse BFS
      void bfs(vector<vector<int>>& heights,
             queue<pair<int,int>>& q,
             vector<vector<bool>>& visited) {

        int rows = heights.size();
        int cols = heights[0].size();

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                // Check boundary
                if(nr < 0 || nr >= rows ||
                   nc < 0 || nc >= cols) {
                    continue;
                }

                // Already visited
                if(visited[nr][nc]) {
                    continue;
                }

                // Reverse water flow:
                // Neighbor must be same or higher
                if(heights[nr][nc] < heights[r][c]) {
                    continue;
                }

                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

};

int main() {
    Solution sol;
    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> heights(m, vector<int>(n));
    cout << "Enter the heights of the cells:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> heights[i][j];
        }
    }

    vector<vector<int>> result = sol.pacificAtlantic(heights);
    cout << "Cells that can reach both oceans:\n";
    for(const auto& cell : result) {
        cout << "[" << cell[0] << ", " << cell[1] << "]\n";
    }

    return 0;
}