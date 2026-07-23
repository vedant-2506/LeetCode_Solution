#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        //TC=O(m+n) SC=O(m+n)
        int rows=grid.size() , cols=grid[0].size();
        queue<pair<int , int>>q;
        vector<vector<bool>>V(rows , vector<bool>(cols , false) );
        int minite;

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c] == 2){
                    q.push( {r,c});
                    V[r][c] = true;
                }
            }
        }

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
          minite=0;

        while(!q.empty()){
            int sz=q.size();
            bool change = false;
            while(sz--){
                auto[r1,c1] = q.front();
                q.pop();
                for(int k=0; k<4; k++){
                    int nr = r1 + dr[k];
                    int nc = c1 + dc[k];

                    if(nr>=0 && nr<rows && nc>=0 && nc<cols){
                        if(grid[nr][nc] == 1 && V[nr][nc]==false){
                            q.push( {nr,nc});
                            grid[nr][nc]=2;
                            V[nr][nc]=true;
                            change=true;
                        }//ig grid
                    }//if nr
                }//for k
            }//while sz

            if(change) minite++;
        }

            for(int r=0; r<rows; r++){
                for(int c=0; c<cols; c++){
                    if(grid[r][c] == 1) return -1;
                }
            }

        return minite;

        
    }
};

int main() {

    Solution sol;

    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));

    cout << "\nEnter the grid values:\n";
    cout << "0 = Empty Cell\n";
    cout << "1 = Fresh Orange\n";
    cout << "2 = Rotten Orange\n\n";

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> grid[i][j];
        }
    }

    int result = sol.orangesRotting(grid);

    cout << "\nResult:\n";

    if(result == -1){
        cout << "It is impossible to rot all fresh oranges." << endl;
    }
    else{
        cout << "Minimum time required to rot all oranges: "
             << result << " minute(s)." << endl;
    }

    return 0;
}