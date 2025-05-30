class Solution {
public:
    int solve(int amount, vector<int>& coins, int n){
        // Base Case
        if(n == 0){
            return (amount % coins[0] == 0);
        }
        int include = 0;
        if(coins[n] <= amount){
            include = solve(amount - coins[n], coins, n);
        }
        int exclude = solve(amount, coins, n-1);
        return (include + exclude);
    }
    int solveUsingMem(int amount, vector<int>&coins, int n, vector<vector<int>>&dp){
        if(n == 0){
            return (amount % coins[0] == 0);
        }
        if(dp[amount][n] != -1){
            return dp[amount][n];
        }
        int include = 0;
        if(coins[n] <= amount){
            include = solveUsingMem(amount - coins[n], coins, n, dp);
        }
        int exclude = solveUsingMem(amount, coins, n-1, dp);
        dp[amount][n] = include + exclude;
        return dp[amount][n];
    }
    int change(int amount, vector<int>& coins) {

        int n = coins.size()-1;
        vector<vector<int>>dp(amount+1, vector<int>(n+1, -1));
        int ans = solveUsingMem(amount, coins, n, dp);
        return ans;
        
    }
};