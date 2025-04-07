class Solution {
public:
    int solveUsingRecursion(int ind, int& stair, vector<int>&cost, vector<int>&dp){
        // Base Case
        if(ind >= cost.size()){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        int ans = INT_MAX;
        int jumpOne = cost[ind] +  solveUsingRecursion(ind+1, stair, cost, dp);
        int jumpTwo = cost[ind] +  solveUsingRecursion(ind+2, stair, cost, dp);
        ans = min(jumpOne, jumpTwo);
        dp[ind] = ans;
        return dp[ind];
    }
    int minCostClimbingStairs(vector<int>& cost) {

        int stair = cost.size();
        vector<int>dp(stair, -1);
        int ans1 = solveUsingRecursion(0, stair, cost, dp);
        int ans2 = solveUsingRecursion(1, stair, cost, dp);
        return min(ans1, ans2);
    }
};