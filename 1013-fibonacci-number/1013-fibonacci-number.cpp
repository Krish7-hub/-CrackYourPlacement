class Solution {
public:
    int solveUsingMem(int n, vector<int>& dp){
        // Base Case
        if(n == 0 || n == 1){
            return n;
        }
        // if already exist then return.
        if(dp[n] != -1){
            return dp[n];
        }
        // store and return using dp array
        dp[n] = solveUsingMem(n-1, dp) + solveUsingMem(n-2, dp);
        return dp[n];
    }
    int fib(int n) {
        // Create dp array.
        vector<int>dp(n+1, -1);
        return solveUsingMem(n, dp);
    }
};