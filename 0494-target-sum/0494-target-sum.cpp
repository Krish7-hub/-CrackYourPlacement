class Solution {
public:
    
    int solveTab(int target, vector<int>&arr){

    int n = arr.size();
    vector<vector<int>>dp(n, vector<int>(target+1, 0));
    // Analyze base case.
    if(arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;

    if(arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= target; j++){
            int include = 0;
            if(arr[i] <= j) include = dp[i-1][j-arr[i]];
            int exclude = dp[i-1][j];
            dp[i][j] = (include + exclude);
        }
    }
    return dp[n-1][target];
}
int countPartitions(int d, vector<int> &arr) {
    // Write your code here.
    int sum = 0;
    for(auto it: arr){
        sum += it;
    }
    int target = (sum - d)/2;
    // Edge Case.
    if((sum - d) < 0 || (sum - d) % 2){
        return 0;
    }
    // vector<vector<int>>dp(n, vector<int>(target+1, -1));
    // int ans = solve(n-1, target, arr, dp);
    int ans = solveTab(target, arr);
    return ans;
}

    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(target, nums);
    }
};