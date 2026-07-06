#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int island=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == '1'){
                    island++;
                    Connected(grid , i , j);
                }
            }
        }
        return island;
    }

    void Connected(vector<vector<char>>& grid, int r, int c){
        queue< pair<int , int>>q;
        grid[r][c]=0;
        q.push({r,c});
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()){
            auto[r1,c1]=q.front();
            q.pop();

            for(int k=0; k<4; k++){
                int nr= r1 +dr[k];
                int nc=c1 +dc[k];
                if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size()){
                    if(grid[nr][nc] == '1'){
                        q.push({nr,nc});
                        grid[nr][nc]= '0';
                    }
                }
            }
        }
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    Solution solution;
    int numberOfIslands = solution.numIslands(grid);
    cout << "Number of islands: " << numberOfIslands << endl;

    return 0;
}