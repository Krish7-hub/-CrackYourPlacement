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
    long long int solveUsingMem(int n, int k, int target, vector<vector<long long>>&dp){
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
        long long int ans = 0;
        for(int i = 1; i <= k; i++){
            if(target - i >= 0)
               ans = (ans) % MOD + (solveUsingMem(n-1, k, target-i, dp)) % MOD;
        }
        dp[n][target] = ans % MOD;
        return dp[n][target] % MOD;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>>dp(n+1, vector<long long>(target+1, -1));
        // int ans = solveUsingRecursion(n, k, target);
        long long int ans = solveUsingMem(n, k, target, dp);
        return ans;
    }
};