class Solution {
public:
    // int solveUsingRecursion(int stair, vector<int>&cost){
    //     // Base Case
    //     if(stair == 0){
    //         return cost[0];
    //     }
    //     if(stair == 1){
    //         return cost[1];
    //     }
    //     int ans = cost[stair] + min(solveUsingRecursion(stair - 1, cost), solveUsingRecursion(stair-2, cost));
    //     return ans;
    // }
    // int solveUsingMem(int stair, vector<int>&cost, vector<int>&dp){
    //     // base case
    //     if(stair == 0){
    //         return cost[0];
    //     }
    //     if(stair == 1){
    //         return cost[1];
    //     }
    //     if(dp[stair] != -1){
    //         return dp[stair];
    //     }
    //     int ans = cost[stair] + min(solveUsingMem(stair - 1, cost, dp), solveUsingMem(stair-2, cost, dp));
    //     dp[stair] = ans;
    //     return dp[stair];
    // }
    int solveUsingTabulation(vector<int>&cost){
        int n = cost.size();
        vector<int>dp(n, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < n; i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // int stair = cost.size();
        // vector<int>dp(stair, -1);
        // int ans = min(solveUsingRecursion(stair - 1, cost), solveUsingRecursion(stair-2, cost));
        // Step -> 1
        // int ans = min(solveUsingMem(stair - 1, cost, dp), solveUsingMem(stair-2, cost, dp));
        int ans = solveUsingTabulation(cost);
        return ans;
    }
};