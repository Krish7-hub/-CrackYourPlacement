class Solution {
public:
    // Using Recursion + Memoization.
    int solveUsingMem(vector<int>&nums, vector<int>&dp,  int ind, int& len){
        // base case 
        if(ind >= len){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        int include = nums[ind] + solveUsingMem(nums, dp, ind + 2, len);
        int exclude = solveUsingMem(nums, dp, ind + 1, len);
        dp[ind] = max(include, exclude);
        return dp[ind];
    }

    // Using Tabulation Methods
    int solveUsingTab(vector<int>& nums){
        // Create dp array.
        int n = nums.size();
        // step 1
        vector<int>dp(n+1, -1);
        
        // step 2
        dp[n-1] = nums[n-1];

        // step 3
        for(int index = n - 2; index >= 0; index--){
            int tempAns = 0;
            if(index + 2 < n){
                tempAns = dp[index + 2];
            }
            int include = nums[index] + tempAns;
            int exclude = 0 + dp[index+1];
            dp[index] = max(include, exclude);
        }
        return dp[0];
    }

    // Space Optimization 
    int solveUsingTabulationSO(vector<int>&nums){
        int n = nums.size();
        int prev = nums[n-1];
        int next = 0;
        int curr = 0;
        for(int index = n - 2; index >= 0; index--){
            // int tempAns = 0;
            // if(index + 2 < n){
            //     tempAns = next;
            // }
            int include = nums[index] + next;
            int exclude = 0 + prev;
            curr = max(include, exclude);
            // bhul jate hai
            next = prev;
            prev = curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        // int len = nums.size();
        // int ind = 0;
        // // Step 1 Create DP array.
        // vector<int>dp(len+1, -1);
        // int ans =  solveUsingMem(nums, dp, ind, len);
        // for(int i = 0; i < len; i++){
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        // return ans;
        // return solveUsingTab(nums);
        return solveUsingTabulationSO(nums);
    }
};