class Solution {
public:
// Solving Using Recursion
    // int solveUsingRecursion(string& text1, string& text2, int n, int m){
    //     // Base Case
    //     if(n == 0 || m == 0){
    //         return 0;
    //     }
    //     if(text1[n-1] == text2[m-1]){
    //         return 1 + solveUsingRecursion(text1, text2, n-1, m-1);
    //     }
    //     else
    //         return max(solveUsingRecursion(text1, text2, n, m-1) , solveUsingRecursion(text1, text2, n-1, m));
    // }
    // Solve Using Recursion + Memoization
    int solveUsingMemoization(string& text1, string& text2, int i, int j, vector<vector<int>>&dp){
        // Base Case 
        if(i >= text1.size() || j >= text2.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(text1[i] == text2[j]){
            ans = 1 + solveUsingMemoization(text1, text2, i+1, j+1, dp);
        }
        else{
            ans = max(solveUsingMemoization(text1, text2, i, j+1, dp), solveUsingMemoization(text1, text2, i+1, j, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        // int ans = solveUsingRecursion(text1, text2, n, m);
        // Create DP Array.
        int i = 0; 
        int j = 0;
        vector<vector<int>>dp(text1.size(), vector<int>(text2.size(), -1));
        int ans = solveUsingMemoization(text1, text2, i, j, dp);
        return ans;
    }
};