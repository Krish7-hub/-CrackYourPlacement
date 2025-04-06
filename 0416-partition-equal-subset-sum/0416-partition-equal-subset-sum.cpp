class Solution {
public:
    // bool solve(int currSum, int& target, int ind, vector<int>&nums){
    //     if(ind >= nums.size()){
    //         return false;
    //     }
    //     if(currSum == target){
    //         return true;
    //     }
    //     bool inc =  solve(currSum + nums[ind], target, ind+1, nums);
    //     bool exc =  solve(currSum, target, ind+1, nums);
    //     return (inc || exc);
    // }
    bool solveUsingMem(int currSum, int& target, int ind, vector<int>&nums, vector<vector<int>>&dp){
        if(ind >= nums.size()){
            return false;
        }
        if(currSum == target){
            return true;
        }
        if(currSum > target){
            return 0;
        }
        if(dp[ind][currSum] != -1){
            return dp[ind][currSum];
        }
        bool inc =  solveUsingMem(currSum + nums[ind], target, ind+1, nums, dp);
        bool exc =  solveUsingMem(currSum, target, ind+1, nums, dp);
        return dp[ind][currSum] = (inc || exc);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if(sum % 2 != 0){
            return false;
        }
        int ind = 0;
        int target = sum / 2;
        int currSum = 0;
        // bool ans = solve(currSum, target, ind, nums);
        vector<vector<int>>dp(nums.size(), vector<int>(target, -1));
        bool ans = solveUsingMem(currSum, target, ind, nums, dp);
        return ans;
    }
};