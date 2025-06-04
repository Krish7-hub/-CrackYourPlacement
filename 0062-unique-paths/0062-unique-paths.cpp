class Solution {
public:
    int solve(int down, int right, int m, int n, vector<vector<int>>&dp){
        // Base Case
        if(down >= m || right >= n){
            return 0;
        }
        if(down == (m-1) && right == (n-1)){
            return 1;
        }
        if(dp[down][right] != -1){
            return dp[down][right];
        }
        int downMove = solve(down+1, right, m, n, dp);
        int rightMove = solve(down, right+1, m, n, dp);
        return dp[down][right] = (downMove + rightMove);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, dp);
        
    }
};