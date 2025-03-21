class Solution {
public:
    int solveUsingMem(int n, vector<int>&dp){
        // Base Case
        if(n == 0 || n == 1){
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        int ans = solveUsingMem(n - 1, dp) + solveUsingMem(n - 2, dp);
        dp[n] = ans;
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        return solveUsingMem(n, dp);
    }
};