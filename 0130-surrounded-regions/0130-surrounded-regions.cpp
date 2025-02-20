class Solution {
public:
    void dfs(vector<vector<char>>&mat, vector<vector<int>>&vis, int row, int col, int delrow[], int delcol[]){
      
      int n = mat.size();
      int m = mat[0].size();
      vis[row][col] = 1;
      
      for(int i = 0; i < 4; i++){
          int nrow = row + delrow[i];
          int ncol = col + delcol[i];
          if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == 'O' && !vis[nrow][ncol]){
              vis[nrow][ncol] = 1;
              dfs(mat, vis, nrow, ncol, delrow, delcol);
          }
      }
  }
    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        vector<vector<int>>vis(n, vector<int>(m, 0));
        
        //traverse first row and last col
        for(int i = 0; i < m; i++){
            if(mat[0][i] == 'O' && !vis[0][i]){
                dfs(mat, vis, 0, i, delrow, delcol);
            }
            if(mat[n-1][i] == 'O' && !vis[n-1][i]){
                dfs(mat, vis, n-1, i, delrow, delcol);
            }
        }
        
        // traverse first col and last col
        for(int i = 0; i < n; i++){
            if(mat[i][0] == 'O' && !vis[i][0]){
                dfs(mat, vis, i, 0, delrow, delcol);
            }
            if(mat[i][m-1] == 'O' && !vis[i][m-1]){
                dfs(mat, vis, i, m-1, delrow, delcol);
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j]){
                    mat[i][j] = 'X';
                }
            }
        }
        // return mat;
    }
};