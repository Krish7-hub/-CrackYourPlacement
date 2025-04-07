class Solution {
public:
    // bool solveUsingRecursion(int ind, int currSum, int& target, vector<int>&nums){
    //     // Base Case
    //     if(ind >= nums.size()){
    //         return false;
    //     }
    //     if(currSum > target){
    //         return false;
    //     }
    //     if(currSum == target){
    //         return true;
    //     }
    //     bool inc = solveUsingRecursion(ind+1, currSum+nums[ind], target, nums);
    //     bool exc = solveUsingRecursion(ind+1, currSum, target, nums);
    //     return (inc || exc);
    // }
    bool solveUsingMem(int ind, int currSum, int& target, vector<int>&nums, vector<vector<int>>&dp){
        // Base Case
        if(ind >= nums.size()){
            return 0;
        }
        if(currSum > target){
            return 0;
        }
        if(currSum == target){
            return 1;
        }
        if(dp[ind][currSum] != -1){
            return dp[ind][currSum];
        }
        bool inc = solveUsingMem(ind+1, currSum+nums[ind], target, nums, dp);
        bool exc = solveUsingMem(ind+1, currSum, target, nums, dp);
        dp[ind][currSum] = (inc || exc);
        return dp[ind][currSum];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if(sum & 1) return false;
        int currSum = 0;
        int ind = 0;
        int target = sum/2;
        // bool ans = solveUsingRecursion(ind, currSum, target, nums);
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        bool ans = solveUsingMem(ind, currSum, target, nums, dp);
        return ans;
    }
};