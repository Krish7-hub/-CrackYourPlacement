class Solution {
public:
    // int solveUsingRecursion(int n, int k, int target){
    //     // Base Case
    //     if(n == 0 && target == 0){
    //         return 1;
    //     }
    //     if(n != 0 && target == 0){
    //         return 0;
    //     }
    //     if(n == 0 && target != 0){
    //         return 0;
    //     }
    //     int ans = 0;
    //     for(int i = 1; i <= k; i++){
    //         ans += solveUsingRecursion(n-1, k, target-i);
    //     }
    //     return ans;
    // }
    long long int MOD = 1e9 + 7;
    int solveUsingMem(int n, int k, int target, vector<vector<int>>&dp){
        // Base Case
        if(n == 0 && target == 0){
            return 1;
        }
        if(n != 0 && target == 0){
            return 0;
        }
        if(n == 0 && target != 0){
            return 0;
        }
        if(dp[n][target] != -1){
            return dp[n][target] % MOD;
        }
        int ans = 0;
        for(int i = 1; i <= k; i++){
            if(target - i >= 0)
               ans = (ans) % MOD + (solveUsingMem(n-1, k, target-i, dp)) % MOD;
        }
        dp[n][target] = ans % MOD;
        return dp[n][target] % MOD;
    }
    int solveUsingTabulation(int n, int k, int target){
        vector<vector<int>>dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= target; j++){
                int ans = 0;
                for(int ind = 1; ind <= k; ind++){
                    if(j - ind >= 0)
                    ans = (ans) % MOD + (dp[i-1][j-ind]) % MOD;
                }
                dp[i][j] = ans % MOD;
            }
        }
        return dp[n][target];
    }
    int solveUsingTabulationSO(int n, int k, int target){
        vector<int>curr(target+1, 0);
        vector<int>prev(target+1, 0);
        // curr[0] = 1;
        prev[0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= target; j++){
                int ans = 0;
                for(int ind = 1; ind <= k; ind++){
                    if(j - ind >= 0)
                    ans = (ans) % MOD + (prev[j-ind]) % MOD;
                }
                curr[j] = ans % MOD;
            }
            prev = curr;
        }
        return curr[target];
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        // int ans = solveUsingRecursion(n, k, target);
        // int ans = solveUsingMem(n, k, target, dp);
        int ans = solveUsingTabulationSO(n, k, target);
        return ans;
    }
};