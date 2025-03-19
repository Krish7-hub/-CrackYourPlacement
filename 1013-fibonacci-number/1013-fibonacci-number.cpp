class Solution {
public:
    int solveUsingMem(int n, vector<int>& dp){
        // Base Case
        if(n == 0 || n == 1){
            return n;
        }
        // if already exist then return.
        if(dp[n] != -1){
            return dp[n];
        }
        // store and return using dp array
        dp[n] = solveUsingMem(n-1, dp) + solveUsingMem(n-2, dp);
        return dp[n];
    }

    int solveUsingTab(int n){
        // This is tabulation method(bottom to up approach.)
        // step 1: Create an dp Array.
        vector<int>dp(n+1, -1);

        // step 2: Analyze base case and fill dp array accordingly.
        dp[0] = 0;
        if(n == 0){
            return dp[0];
        }
        dp[1] = 1;

        // fill remaining dp array using recursive relation.
        // index -> 0 to n as size of array is n + 1.
        // index of 0 is 0 and index of 1 is 1.
        // remaining size is n - 2 i.e from 2 to n.
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        // so final ans will store in dp[n].
        return dp[n];
    }

    int fib(int n) {
        // Create dp array.
        // vector<int>dp(n+1, -1);
        // return solveUsingMem(n, dp);
        return solveUsingTab(n);
    }
};