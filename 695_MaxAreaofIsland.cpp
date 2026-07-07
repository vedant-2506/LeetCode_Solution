#include<iostream>
#include<queue>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        //TC=O(m*n) SC=O(m*n)
        int maxarea=0 , area=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    area =  maxArea(grid , i , j);
                    maxarea = max(maxarea , area);
                }
            }
        }
        return maxarea;
    }

    int maxArea(vector<vector<int>>&grid, int r , int c){
        queue<pair<int,int>>q;
        grid[r][c]=0;
        q.push({r,c});
        int area = 1;
        while(!q.empty()){
            auto[r1 ,c1] = q.front();
            q.pop();
            int dr[]={-1,1,0,0};
            int dc[]={0,0,-1,1};
            int nr=0 , nc=0;
            for(int k=0; k<4; k++){
                nr = r1 + dr[k];
                nc = c1 + dc[k];
            
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc] == 1){
                q.push({nr , nc});
                grid[nr][nc]=0;
                area++;
            }
            }
        }
        return area;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                 {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                 {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                 {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                 {0,0,0,0,0,0,0,1 , 2 , 3 , 4 , 5 , 6}};
    cout<<s.maxAreaOfIsland(grid);
    cout<<endl;
    return  0;
}