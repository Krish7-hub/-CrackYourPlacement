class Solution {
public:
    int solve(int m, int n, vector<vector<int>>&grid){
        // Base Case
        if(m < 0 || n < 0){
            return 0;
        }
        if(grid[m][n] == 1){
            return 0;
        }
        if(m == 0 && n == 0){
            return 1;
        }
        int upMove = solve(m-1, n, grid);
        int leftMove = solve(m, n-1, grid);
        return upMove + leftMove;
    }
    int solveMem(int m, int n, vector<vector<int>>&grid, vector<vector<int>>&dp){
        // Base Case
        if(m < 0 || n < 0){
            return 0;
        }
        if(grid[m][n] == 1){
            return 0;
        }
        if(m == 0 && n == 0){
            return 1;
        }
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        int upMove = solveMem(m-1, n, grid, dp);
        int leftMove = solveMem(m, n-1, grid, dp);
        dp[m][n] = upMove + leftMove; 
        return dp[m][n];
    }
    int solveTab(int m, int n, vector<vector<int>>&grid){
        vector<vector<int>>dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else if(grid[i][j] != 1){
                    int upMove = 0, leftMove = 0;
                    if(i > 0) upMove = dp[i-1][j];
                    if(j > 0) leftMove = dp[i][j-1];
                    dp[i][j] = upMove + leftMove; 
                }
            }
        } 
        return dp[m-1][n-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        // return solve(m-1, n-1, grid);
        // return solveMem(m-1, n-1, grid, dp);
        return solveTab(m, n, grid);
    }
};