class Solution {
public:
    int solveUsingRecursion(int ind, vector<int>&coins, int target){
        // Base Case
        if(target == 0){
            return 0;
        }
        if(target < 0){
            return INT_MAX;
        }
        // Processing
        int ans = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            int recursionAns = solveUsingRecursion(i+1, coins, target - coins[i]);
            if(recursionAns != INT_MAX){
                ans = 1 + min(ans, recursionAns);
            }
        }
        return ans;
    }
    int solveUsingMem(vector<int>&coins, int target, vector<int>&dp){
        // Base Case
        if(target == 0){
            return 0;
        }
        if(dp[target] != -1){
            return dp[target];
        }
        // Processing
        int mini = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            if(target - coins[i] >= 0){
                int recursionAns = solveUsingMem(coins, target - coins[i], dp);
                if(recursionAns != INT_MAX){
                    int ans = 1 + recursionAns;
                    mini = min(ans, mini);
                }
            }
        }
        dp[target] = mini;
        return dp[target];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>dp(amount+1, -1);
        // int ans = solveUsingRecursion(ind, coins, amount);
        int ans = solveUsingMem(coins, amount, dp);
        if(ans != INT_MAX)  return ans; 
        return -1;
    }
};