class Solution {
public:
    int solve(int row, int col, int& m, int& n){
        // Base case
        if(row >= m || col >= n){
            return 0;
        }
        if(row == (m-1) && col == (n-1)){
            return 1;
        }
        int downMove = solve(row+1, col, m, n);
        int rightMove = solve(row, col+1, m, n);
        return (downMove + rightMove);
    }
    int solveMem(int row, int col, int& m, int& n, vector<vector<int>>&dp){
        // Base case
        if(row >= m || col >= n){
            return 0;
        }
        if(row == (m-1) && col == (n-1)){
            return 1;
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        int downMove = solveMem(row+1, col, m, n, dp);
        int rightMove = solveMem(row, col+1, m, n, dp);
        dp[row][col] = (downMove + rightMove);
        return dp[row][col];
    }
    int solveTab(int m, int n){
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(i == m-1 && j == n-1){
                    dp[i][j] = 1;
                }
                else{
                    int downMove = dp[i+1][j];
                    int rightMove = dp[i][j+1];
                    dp[i][j] = downMove + rightMove;
                }
            }
        }
        return dp[0][0];
    }
    int uniquePaths(int m, int n) {
        // return solve(0, 0, m, n);
        // vector<vector<int>>dp(m, vector<int>(n, -1));
        // return solveMem(0, 0, m, n, dp);
        return solveTab(m, n);
    }
};