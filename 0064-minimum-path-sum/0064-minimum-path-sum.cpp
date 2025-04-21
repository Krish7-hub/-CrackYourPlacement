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
    // int solveTabulation(vector<vector<int>>&grid){
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     vector<vector<int>>dp(m, vector<int>(n, -1));
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        int ans = solveRecursion(m-1, n-1, m, n, grid, dp);
        return ans;
    }
};