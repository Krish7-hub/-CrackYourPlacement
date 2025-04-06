class Solution {
public:
    int maxVal(int start, int end, vector<int>&arr){
        int maxi = INT_MIN;
        for(int i = start; i <= end; i++){
            if(arr[i] > maxi){
                maxi = arr[i];
            }
        }
        return maxi;
    }
    int solveUsingRecursion(int left, int right, vector<int>&arr, vector<vector<int>>&dp){
        // Base Case
        // if(right == arr.size()-1){
        //     return 0;
        // }
        if(left == right){
            return 0;
        }
        if(dp[left][right] != -1){
            return dp[left][right];
        }
        // Processing
        int ans = INT_MAX;
        for(int k = left; k < right; k++){
            ans = min(ans, maxVal(left, k, arr) * maxVal(k+1, right, arr) + solveUsingRecursion(left, k, arr, dp) + solveUsingRecursion(k+1, right, arr, dp));
        }
        dp[left][right] = ans;
        return dp[left][right];
    }
    int mctFromLeafValues(vector<int>& arr) {
        int len = arr.size();
        int left = 0;
        int right = len - 1;
        vector<vector<int>>dp(len+1, vector<int>(len+1, -1));
        int ans = solveUsingRecursion(left, right, arr, dp);
        return ans;
        
    }
};