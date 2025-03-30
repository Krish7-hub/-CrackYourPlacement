class Solution {
public:
    // Solve Using Recursion.
    int solveUsingRecursion(string& word1, string& word2, int i, int j){
        // Base Case
        if(i == word1.length()){
            return word2.length()-j;
        }
        if(j == word2.length()){
            return word1.length()-i;
        }
        int ans = 0;
        if(word1[i] == word2[j]){
            ans = 0 + solveUsingRecursion(word1, word2, i+1, j+1);
        }
        else{
            int replace = 1 + solveUsingRecursion(word1, word2, i+1, j+1);
            int insert = 1 + solveUsingRecursion(word1, word2, i, j+1);
            int remove = 1 + solveUsingRecursion(word1, word2, i+1, j);
            ans = min(replace, min(insert, remove));
        }
        return ans;
    }

    int solveUsingMem(string& word1, string& word2, int i, int j, vector<vector<int>>&dp){
        // Base Case
        if(i == word1.length()){
            return word2.length()-j;
        }
        if(j == word2.length()){
            return word1.length()-i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(word1[i] == word2[j]){
            ans = 0 + solveUsingMem(word1, word2, i+1, j+1, dp);
        }
        else{
            int replace = 1 + solveUsingMem(word1, word2, i+1, j+1, dp);
            int insert = 1 + solveUsingMem(word1, word2, i, j+1, dp);
            int remove = 1 + solveUsingMem(word1, word2, i+1, j, dp);
            ans = min(replace, min(insert, remove));
        }
        dp[i][j] = ans;
        return ans;
    }

    int minDistance(string word1, string word2) {

        int i = 0; 
        int j = 0;
        // int ans = solveUsingRecursion(word1, word2, i, j);
        vector<vector<int>>dp(word1.size()+1, vector<int>(word2.size()+1, -1));
        int ans = solveUsingMem(word1, word2, i, j, dp);
        return ans;

    }
};