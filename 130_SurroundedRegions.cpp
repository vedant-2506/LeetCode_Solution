#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {

        // Boundary BFS TC=O(m*n) SC=O(m*n)
        int rows=board.size() , cols=board[0].size();
        for(int c=0; c<cols; c++){
            if(board[0][c] == 'O') dfs(0, c , board);
        }
        for(int r=0; r<rows; r++){
            if(board[r][0] == 'O') dfs(r , 0 , board);
        }
        for(int c=0; c<cols; c++){
            if(board[rows-1][c] == 'O') dfs(rows-1 , c , board);
        }
        for(int r=0; r<rows; r++){
            if(board[r][cols-1] == 'O') dfs(r , cols-1 , board);
        }

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(board[r][c] == 'O') board[r][c] = 'X';
                else if(board[r][c] == '1') board[r][c] = 'O';
            }
        }
        
    }

    void dfs(int r , int c , vector<vector<char>>&board){
        queue<pair<int , int>>q;
        q.push({r , c});
        board[r][c] = '1';
        int dr[] = {-1 , 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()){
            auto[r1 , c1] = q.front();
            q.pop();
            for(int k=0; k<4; k++){
                int nr = r1 + dr[k];
                int nc = c1 + dc[k];

                if(nr>= 0 && nr<board.size() && nc>=0 && nc<board[0].size()){
                    if(board[nr][nc] == 'O'){
                        q.push({nr , nc});
                        board[nr][nc] = '1';
                    }
                }        
            }
        }
    }
};

int main() {

    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> cols;

    vector<vector<char>> board(rows, vector<char>(cols));

    cout << "\nEnter the board elements (X or O):\n";
    cout << "Enter one row at a time.\n";

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> board[i][j];
        }
    }

    cout << "\nOriginal Board:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    Solution obj;
    obj.solve(board);

    cout << "\nBoard after processing:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}