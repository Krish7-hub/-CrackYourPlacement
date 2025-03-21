class Solution {
public:
    // Using Recursion + Memoization.
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
    // Using Tabulation Method
    int solveUsingTab(int n){
        vector<int>dp(n+1, -1);
        dp[0] = 1;
        if(n == 0){
            return dp[0];
        }
        dp[1] = 1;
        if(n == 1){
            return dp[1];
        }
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    // Space Optimization
    int solveUsingTabSO(int n){
        int prev = 1;
        int curr = 1;
        if(n == 0 || n == 1){
            return 1;
        }
        int ans = 0;
        for(int i = 2; i <= n; i++){
            ans = prev + curr;
            prev = curr;
            curr = ans;
        }
        return ans;
    }
    int climbStairs(int n) {
        // vector<int>dp(n+1, -1);
        // return solveUsingMem(n, dp);
        return solveUsingTabSO(n);
    }
};