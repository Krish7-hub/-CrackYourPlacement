class Solution {
public:
    int solveUsingRecursion(int ind, vector<int>&nums){
        // Base Case
        if(ind >= nums.size()){
            return 0;
        }
        int inc = nums[ind] + solveUsingRecursion(ind+2, nums);
        int exc = solveUsingRecursion(ind+1, nums);
        return max(inc, exc);
    }
    int solveUsingMem(int ind, vector<int>&nums, vector<int>&dp){
        // Base Case
        if(ind >= nums.size()){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        int inc = nums[ind] + solveUsingMem(ind+2, nums, dp);
        int exc = solveUsingMem(ind+1, nums, dp);
        dp[ind] = max(inc, exc);
        return dp[ind];
    }
    int solveUsingTabulation(vector<int>&nums){
        int n = nums.size();
        vector<int>dp(n+2, 0);
        for(int ind = n-1; ind >= 0; ind--){
            int inc = nums[ind] + dp[ind+2];
            int exc = dp[ind+1];
            dp[ind] = max(inc, exc);
        }
        return dp[0];
    }
    int solveUsingTabulationSO(vector<int>&nums){
        int n = nums.size();
        // vector<int>dp(n+2, 0);
        int next = 0;
        int next2 = 0;
        for(int ind = n-1; ind >= 0; ind--){
            int inc = nums[ind] + next2;
            int exc = next;
            int curr = max(inc, exc);
            next2 = next;
            next = curr;
        }
        return next;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ind = 0;
        // int ans = solveUsingRecursion(ind, nums);
        // vector<int>dp(n, -1);
        // int ans = solveUsingMem(ind, nums, dp);
        int ans = solveUsingTabulationSO(nums);
        return ans;
    }
};