class Solution {
public:
    // Using Recursion.
    int solveUsingRecursion(int curr, int prev, vector<int>&nums){
        if(curr >= nums.size()){
            return 0;
        }
        int ans = 0;
        int include = 0;
        if(nums[curr] > prev){
            include = 1 + solveUsingRecursion(curr + 1, nums[curr] , nums);
        }
        int exclude = 0 + solveUsingRecursion(curr + 1, prev, nums);
        ans = max(include, exclude);
        return ans;
    }
    // Solve Using Recursion + Memoization.
    int solveUsingMem(int curr, int prev, vector<int>&nums, vector<vector<int>>&dp){
        // Base Case
        if(curr >= nums.size()){
            return 0;
        }
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solveUsingMem(curr+1, curr, nums, dp);
        }
        int exclude = solveUsingMem(curr + 1, prev, nums, dp);
        int ans = max(include, exclude);
        dp[curr][prev+1] = ans;
        return dp[curr][prev+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1;
        // int ans = solveUsingRecursion(curr, prev, nums);
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        int ans = solveUsingMem(curr, prev, nums, dp);
        return ans;
    }
};