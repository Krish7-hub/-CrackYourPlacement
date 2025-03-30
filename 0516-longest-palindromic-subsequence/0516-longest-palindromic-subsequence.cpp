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
    // Solve Using Tabulation.
    int solveUsingTabulation(string& s, string& s2){
        // Step -> 1 Create DP array.
        vector<vector<int>>dp(s.size()+1, vector<int>(s2.size()+1, 0));
        for(int i = s.size()-1; i >= 0; i--){
            for(int j = s2.size()-1; j >= 0; j--){
                int ans = 0;
                if(s[i] == s2[j]){
                    ans =  1 + dp[i+1][j+1];
                }
                else{
                    ans =  max(dp[i][j+1], dp[i+1][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    // Space Optimizaton.
    int solveUsingTabulationSO(string& s, string& s2){
        // Step -> 1 Create 2 vector array.
        vector<int>curr(s.size()+1, 0);
        vector<int>next(s.size()+1, 0);

        for(int j = s2.size()-1; j >= 0; j--){
            for(int i = s.size()-1; i >= 0; i--){
                int ans = 0;
                if(s[i] == s2[j]){
                    ans =  1 + next[i+1];
                }
                else{
                    ans =  max(next[i], curr[i+1]);
                }
                curr[i] = ans;
            }
            // Shifting
            next = curr;
        }
        return curr[0];
    }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int i = 0;
        int j = 0;
        // vector<vector<int>>dp(s.size()+1, vector<int>(s2.size()+1, -1));
        // int ans = solveUsingMem(s, s2, i, j, dp);
        // int ans = solveUsingRecursion(s, s2, i, j);
        // int ans = solveUsingTabulation(s, s2);
        int ans = solveUsingTabulationSO(s, s2);
        return ans;
    }
};