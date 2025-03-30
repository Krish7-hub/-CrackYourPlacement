class Solution {
public:
    // Solving Using Recursion.
    int solveUsingRecursion(string& s, string& s2, int i, int j){
        // base case
        if(i >= s.size() || j >= s2.size()){
            return 0;
        }

        int ans = 0;
        if(s[i] == s2[j]){
            ans =  1 + solveUsingRecursion(s, s2, i+1, j+1);
        }
        else{
            ans =  max(solveUsingRecursion(s, s2, i, j+1), solveUsingRecursion(s, s2, i+1, j));
        }
        return ans;
    }
    // Solve Using Recursion + Memoization.
    int solveUsingMem(string& s, string& s2, int i, int j, vector<vector<int>>&dp){
        // base case
        if(i >= s.size() || j >= s2.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(s[i] == s2[j]){
            ans =  1 + solveUsingMem(s, s2, i+1, j+1, dp);
        }
        else{
            ans =  max(solveUsingMem(s, s2, i, j+1, dp), solveUsingMem(s, s2, i+1, j, dp));
        }
        dp[i][j] = ans;
        return ans;
    }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int i = 0;
        int j = 0;
        vector<vector<int>>dp(s.size()+1, vector<int>(s2.size()+1, -1));
        int ans = solveUsingMem(s, s2, i, j, dp);
        // int ans = solveUsingRecursion(s, s2, i, j);
        return ans;
    }
};