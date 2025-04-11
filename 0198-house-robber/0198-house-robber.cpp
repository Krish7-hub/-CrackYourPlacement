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
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ind = 0;
        // int ans = solveUsingRecursion(ind, nums);
        vector<int>dp(n, -1);
        int ans = solveUsingMem(ind, nums, dp);
        return ans;
    }
};