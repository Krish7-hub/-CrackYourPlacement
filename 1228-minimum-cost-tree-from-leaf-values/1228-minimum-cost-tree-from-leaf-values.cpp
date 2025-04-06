class Solution {
public:
    int solveUsingRecursion(int left, int right, vector<int>&arr,  map<pair<int, int>, int>&maxi, vector<vector<int>>&dp){
        // Base Case
        if(left == right){
            return 0;
        }
        if(dp[left][right] != -1){
            return dp[left][right];
        }
        // Processing
        int ans = INT_MAX;
        for(int k = left; k < right; k++){
            ans = min(ans, maxi[{left, k}] * maxi[{k+1, right}] + solveUsingRecursion(left, k, arr, maxi, dp) + solveUsingRecursion(k+1, right, arr, maxi, dp));
        }
        dp[left][right] = ans;
        return dp[left][right];
    }
    int solveUsingTabulation(vector<int>&arr, map<pair<int, int>, int>&maxi){
        // base Case analysis.
        int n = arr.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int left = n-1; left >= 0; left--){
            for(int right = 0; right < n; right++){
                int ans = INT_MAX;
                for(int k = left; k < right; k++){
                    ans = min(ans, maxi[{left, k}] * maxi[{k+1, right}] + solveUsingRecursion(left, k, arr, maxi, dp) + solveUsingRecursion(k+1, right, arr, maxi, dp));
                }
                dp[left][right] = ans;
            }
        }   
        return dp[0][n-1];
    }
    int mctFromLeafValues(vector<int>& arr) {
        int len = arr.size();
        int left = 0;
        int right = len - 1;
        map<pair<int, int>, int>maxi;
        for(int i = 0; i < len; i++){
            maxi[{i, i}] = arr[i];
            for(int j = i+1; j < len; j++){
                maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }
        vector<vector<int>>dp(len+1, vector<int>(len+1, -1));
        // int ans = solveUsingRecursion(left, right, arr, maxi, dp);
        int ans = solveUsingTabulation(arr, maxi);
        return ans;
        
    }
};