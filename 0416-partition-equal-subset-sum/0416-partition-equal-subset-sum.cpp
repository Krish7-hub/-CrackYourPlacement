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
    bool solveUsingTabulation(vector<int>& nums, int& target){
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(target+1, 0));
        for(int row = 0; row <= n; row++){
            dp[row][target] = 1;
        }
        for(int ind = n-1; ind >= 0; ind--){
            for(int s = target; s >= 0; s--){
                bool inc = 0;
                if(s + nums[ind] <= target){
                    inc =  dp[ind+1][s + nums[ind]];
                }
                bool exc =  dp[ind+1][s];
                dp[ind][s] = (inc || exc);
            }
        }
        return dp[0][0];
    }
    bool solveUsingTabulationSO(vector<int>& nums, int& target){
        int n = nums.size();
        // vector<vector<int>>dp(n+1, vector<int>(target+1, 0));
        vector<int>curr(target+1, 0);
        vector<int>next(target+1, 0);

        curr[target] = 1;
        next[target] = 1;

        for(int ind = n-1; ind >= 0; ind--){
            for(int s = target; s >= 0; s--){
                bool inc = 0;
                if(s + nums[ind] <= target){
                    inc =  next[s + nums[ind]];
                }
                bool exc =  next[s];
                curr[s] = (inc || exc);
            }
            next = curr;
        }
        return curr[0];
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
        // int currSum = 0;
        // bool ans = solve(currSum, target, ind, nums);
        // vector<vector<int>>dp(nums.size(), vector<int>(target, -1));
        // bool ans = solveUsingMem(currSum, target, ind, nums, dp);
        bool ans = solveUsingTabulationSO(nums, target);
        return ans;
    }
};