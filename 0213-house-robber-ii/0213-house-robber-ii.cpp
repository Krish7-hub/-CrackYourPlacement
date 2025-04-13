class Solution {
public:
    int solveUsingRecursion(int ind, vector<int>&arr, vector<int>&dp){
        // Base Case
        if(ind >= arr.size()){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        int inc = arr[ind] + solveUsingRecursion(ind+2, arr, dp);
        int exc = solveUsingRecursion(ind+1, arr, dp);
        dp[ind] = max(inc, exc);
        return dp[ind];
    }

    int rob(vector<int>& nums) {
        int ind = 0;
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>dp1(n-1, -1), dp2(n-1, -1);
        vector<int>arr1, arr2;
        for(int i = 0; i < nums.size(); i++){
            if(i != n-1){
                arr1.push_back(nums[i]);
            }
            if(i != 0){
                arr2.push_back(nums[i]);
            }
        }
        int ans1 = solveUsingRecursion(ind, arr1, dp1);
        int ans2 = solveUsingRecursion(ind, arr2, dp2);
        return max(ans1, ans2);
    }
};