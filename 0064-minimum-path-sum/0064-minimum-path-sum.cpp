class Solution {
public:
    int solveRecursion(int i, int j, int m, int n, vector<vector<int>>&grid, vector<vector<int>>&dp){
        // Base Case 
        if(i < 0 || j < 0){
            return 100000;
        }
        if(i == 0 && j == 0){
            return grid[0][0];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int leftMove = grid[i][j] + solveRecursion(i, j-1, m, n, grid, dp);
        int upMove = grid[i][j] + solveRecursion(i-1, j, m, n, grid, dp);
        dp[i][j] = min(leftMove, upMove);
        return dp[i][j];
    }
    int solveTabulation(vector<vector<int>>&grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[i][j];
                }
                else{
                    int leftMove = 100000, upMove = 100000; 
                    if(j > 0) leftMove = grid[i][j] + dp[i][j-1];
                    if(i > 0) upMove = grid[i][j] + dp[i-1][j];
                    dp[i][j] = min(leftMove, upMove);
                }
            }
        }
        return dp[m-1][n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        // int m = grid.size();
        // int n = grid[0].size();
        // vector<vector<int>>dp(m, vector<int>(n, -1));
        // int ans = solveRecursion(m-1, n-1, m, n, grid, dp);
        int ans = solveTabulation(grid);
        return ans;
    }
};