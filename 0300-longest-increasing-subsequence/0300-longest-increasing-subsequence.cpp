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
    // Solve Using Tabulation Method
    int solveUsingTabulation(vector<int>&nums){
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

        for(int curr_index = nums.size()-1; curr_index >= 0; curr_index--){
            for(int prev_index = curr_index-1; prev_index >= -1; prev_index--){
                int include = 0;
                if(prev_index == -1 || nums[curr_index] > nums[prev_index]){
                    include = 1 + dp[curr_index+1][curr_index+1];
                }
                int exclude = dp[curr_index + 1][prev_index+1];
                int ans = max(include, exclude);
                dp[curr_index][prev_index+1] = ans;
            }
        }
        return dp[0][0];
    }
    // Space Optimization
    int solveUsingTabulationSO(vector<int>&nums){
        int n = nums.size();
        vector<int>currRow(n+1, 0);
        vector<int>nextRow(n+1, 0);

        for(int curr_index = nums.size()-1; curr_index >= 0; curr_index--){
            for(int prev_index = curr_index-1; prev_index >= -1; prev_index--){
                int include = 0;
                if(prev_index == -1 || nums[curr_index] > nums[prev_index]){
                    include = 1 + nextRow[curr_index+1];
                }
                int exclude = nextRow[prev_index+1];
                int ans = max(include, exclude);
                currRow[prev_index+1] = ans;
            }
            // Shifing
            nextRow = currRow;
        }
        return currRow[0];
    }
    // Solve Using Binary Search Algorithm
    int solveUsingBinarySearch(vector<int>&nums){
        // ans vector
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                // replace
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1;
        // int ans = solveUsingRecursion(curr, prev, nums);
        int n = nums.size();
        // vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        // int ans = solveUsingMem(curr, prev, nums, dp);
        // int ans = solveUsingTabulation(nums);
        // int ans = solveUsingTabulationSO(nums);
        int ans = solveUsingBinarySearch(nums);
        return ans;
    }
};