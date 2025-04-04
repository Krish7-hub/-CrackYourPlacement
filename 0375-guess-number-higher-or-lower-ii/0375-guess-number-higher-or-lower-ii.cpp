class Solution {
public:
    int solveUsingRecursion(int start, int end){
        // Base Case 
        if(start > end){
            return 0;
        }
        if(start == end){
            return 0;
        }
        int ans = INT_MAX;
        for(int i = start; i <= end; i++){
            ans = min(ans, i + max(solveUsingRecursion(start, i-1), solveUsingRecursion(i+1, end)));
        }
        return ans;
    }

    int solveUsingMem(int start, int end, vector<vector<int>>&dp){
        // Base Case 
        if(start > end){
            return 0;
        }
        if(start == end){
            return 0;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        int ans = INT_MAX;
        for(int i = start; i <= end; i++){
            ans = min(ans, i + max(solveUsingMem(start, i-1, dp), solveUsingMem(i+1, end, dp)));
        }
        dp[start][end] = ans;
        return dp[start][end];
    }

    int solveUsingTabulation(int n){
        vector<vector<long>>dp(n+2, vector<long>(n+2, 0));
        for(int start = n; start >= 1; start--){
            for(int end = 1; end <= n; end++){
                if(start == end){
                    continue;
                }

                else{
                    long ans = INT_MAX;
                    for(int i = start; i <= end; i++){
                        ans = min(ans, i + max(dp[start][i-1], dp[i+1][end]));
                    }
                    dp[start][end] = ans;
                }
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        int start = 1; 
        int end = n;
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        // int ans = solveUsingMem(start, end, dp);
        int ans = solveUsingTabulation(n);
        return ans;
    }
};