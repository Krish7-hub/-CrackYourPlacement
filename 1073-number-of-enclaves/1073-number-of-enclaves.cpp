class Solution {
public:
    // void dfs(vector<vector<int>>& grid, vector<vector<int>>&vis, int row, int col, int delrow[], int delcol[]){
    //     vis[row][col] = 1;
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     for(int i = 0; i < 4; i++){
    //         int nrow = row + delrow[i];
    //         int ncol = col + delcol[i];
    //         if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
    //             vis[nrow][ncol] = 1;
    //             dfs(grid, vis, nrow, ncol, delrow, delcol);
    //         }
    //     }
    // }
    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        vector<vector<int>>vis(m, vector<int>(n, 0));
        queue<pair<int, int>>q;

        // traverse first row and last row
        for(int i = 0; i < n; i++){
            if(grid[0][i] == 1 && !vis[0][i]){
                q.push({0, i});
            }
            if(grid[m-1][i] == 1 && !vis[m-1][i]){
                q.push({m-1, i});
            }
        }
        // traverse first col and last col
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 1 && !vis[i][0]){
               q.push({i, 0});
            }
            if(grid[i][n-1] == 1 && !vis[i][n-1]){
                q.push({i, n-1});
            }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            vis[row][col] = 1;
            for(int i = 0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        int countEnclaves = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    countEnclaves++;
                }
            }
        }

        return countEnclaves;
        
    }
};