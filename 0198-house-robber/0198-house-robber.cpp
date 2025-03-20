class Solution {
public:
    int solve(vector<int>&nums, vector<int>&dp,  int ind, int& len){
        // base case 
        if(ind >= len){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        dp[ind] = nums[ind] + solve(nums, dp, ind + 2, len);
        dp[ind+1] = solve(nums, dp, ind + 1, len);
        return max(dp[ind] , dp[ind+1]);
    }
    int rob(vector<int>& nums) {
        int len = nums.size();
        int ind = 0;
        // Step 1 Create DP array.
        vector<int>dp(len+1, -1);
        return solve(nums, dp, ind, len);
    }
};