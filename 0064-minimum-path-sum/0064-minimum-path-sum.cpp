class Solution {
public:
    int solveRecursion(int i, int j, int m, int n, vector<vector<int>>&grid, vector<vector<int>>&dp){
        // Base Case 
        if(i >= m || j >= n){
            return 100000;
        }
        if(i == (m-1) && j == (n-1)){
            return grid[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int rightMove = grid[i][j] + solveRecursion(i, j+1, m, n, grid, dp);
        int downMove = grid[i][j] + solveRecursion(i+1, j, m, n, grid, dp);
        dp[i][j] = min(rightMove, downMove);
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        int ans = solveRecursion(0, 0, m, n, grid, dp);
        return ans;
    }
};