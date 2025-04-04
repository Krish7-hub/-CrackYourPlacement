class Solution {
public:
    int solveUsingRecursion(vector<int>& coins, int amount){
        // Base Case
        if(amount == 0){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }
        int mini = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            int recursionAns = solveUsingRecursion(coins, amount - coins[i]);
            if(recursionAns != INT_MAX){
                mini = 1 + min(mini, recursionAns);
            }
        }
        return mini;
    }
    // Recursion + Memoization.
    int solveUsingMem(vector<int>& coins, int amount, vector<int>&dp){
        // Base Case
        if(amount == 0){
            return 0;
        }
        if(dp[amount] != -1){
            return dp[amount];
        }
        int mini = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            if(amount - coins[i] >= 0){
                int recursionAns = solveUsingMem(coins, amount - coins[i], dp);
                if(recursionAns != INT_MAX){
                    int ans = 1 + recursionAns;
                    mini = min(mini, ans);
                }
            }
        }
        // step - 2.
        dp[amount] = mini;
        return dp[amount];
    }
    int solveUsingTab(vector<int>& coins, int amount){
        // Step 1 
        int n = amount;
        vector<int>dp(n + 1, INT_MAX);
        // analyze base case
        dp[0] = 0;
        for(int val = 1; val <= amount; val++){
            int mini = INT_MAX;
            for(int i = 0; i < coins.size(); i++){
                if(val - coins[i] >= 0){
                    int recursionAns = dp[val - coins[i] ];
                    if(recursionAns != INT_MAX){
                        int ans = 1 + recursionAns;
                        mini = min(mini, ans);
                    }
                }
            }
            dp[val] = mini;
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // int ans = solveUsingRecursion(coins, amount);
        // step 1
        // vector<int>dp(amount + 1, -1);
        // int ans1 = solveUsingMem(coins, amount, dp);
        int ans2 = solveUsingTab(coins, amount);
        if(ans2 == INT_MAX){
            return -1;
        }
        else{
            return ans2;
        }
    }
};