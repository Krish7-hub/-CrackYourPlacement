class Solution {
public:
    int solveUsingMem(int ind, vector<int>&arr, vector<int>&dp){
        // Base Case
        if(ind >= arr.size()){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        int inc = arr[ind] + solveUsingMem(ind+2, arr, dp);
        int exc = solveUsingMem(ind+1, arr, dp);
        dp[ind] = max(inc, exc);
        return dp[ind];
    }

    int solveUsingTabulation(vector<int>&nums){
        int n = nums.size();
        vector<int>arr1,arr2;
        vector<int>dp1(n+2, 0), dp2(n+2,0);
        for(int i = 0; i < nums.size(); i++){
            if(i != n-1){
                arr1.push_back(nums[i]);
            }
            if(i != 0){
                arr2.push_back(nums[i]);
            }
        }
        for(int i = n-2; i >= 0; i--){
            int inc = arr1[i] + dp1[i+2];
            int exc = dp1[i+1];
            dp1[i] = max(inc, exc);
        }
        for(int i = n-2; i >= 0; i--){
            int inc = arr2[i] + dp2[i+2];
            int exc = dp2[i+1];
            dp2[i] = max(inc, exc);
        }
        return max(dp1[0], dp2[0]);
    }

    int rob(vector<int>& nums) {
        // int ind = 0;
        int n = nums.size();
        if(n == 1) return nums[0];
        // vector<int>dp1(n-1, -1), dp2(n-1, -1);
        // vector<int>arr1, arr2;
        // for(int i = 0; i < nums.size(); i++){
        //     if(i != n-1){
        //         arr1.push_back(nums[i]);
        //     }
        //     if(i != 0){
        //         arr2.push_back(nums[i]);
        //     }
        // }
        // int ans1 = solveUsingTabulation(arr1);
        // int ans2 = solveUsingTabulation(arr2);
        return solveUsingTabulation(nums);
    }
};