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
    // Solve Using Memoization.
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
    // Solve Using Tabulation.
    int solveUsingTabulation(string& word1, string& word2){
        vector<vector<int>>dp(word1.length()+1, vector<int>(word2.length()+1, -1));
        for(int row = 0; row <= word1.length(); row++){
            dp[row][word2.length()] =  word1.length()-row;
        }
        for(int col = 0; col <= word2.size(); col++){
            dp[word1.length()][col] = word2.length()-col;
        }
        for(int i = word1.length()-1; i >= 0; i--){
            for(int j = word2.length()-1; j >= 0; j--){
                 int ans = 0;
                 if(word1[i] == word2[j]){
                    ans = 0 + dp[i+1][j+1];
                }
                else{
                    int replace = 1 + dp[i+1][j+1];
                    int insert = 1 + dp[i][j+1];
                    int remove = 1 + dp[i+1][j];
                    ans = min(replace, min(insert, remove));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int solveUsingTabulationSO(string& word1, string& word2){
        // vector<vector<int>>dp(word1.length()+1, vector<int>(word2.length()+1, -1));
        vector<int>curr(word1.length()+1, 0);
        vector<int>next(word1.length()+1, 0);

        for(int row = 0; row <= word1.length(); row++){
            next[row] =  word1.length()-row;
        }
        for(int j = word2.length()-1; j >= 0; j--){
            curr[word1.length()] = word2.length()-j;
            for(int i = word1.length()-1; i >= 0; i--){
                int ans = 0;
                if(word1[i] == word2[j]){
                    ans = 0 + next[i+1];
                }
                else{
                    int replace = 1 + next[i+1];
                    int insert = 1 + next[i];
                    int remove = 1 + curr[i+1];
                    ans = min(replace, min(insert, remove));
                }
                curr[i] = ans;
            }
            // Shifting
            next = curr;
        }
        return next[0];
    }
    int minDistance(string word1, string word2) {

        int i = 0; 
        int j = 0;
        // int ans = solveUsingRecursion(word1, word2, i, j);
        // vector<vector<int>>dp(word1.size()+1, vector<int>(word2.size()+1, -1));
        // int ans = solveUsingMem(word1, word2, i, j, dp);
        // int ans = solveUsingTabulation(word1, word2);
        int ans = solveUsingTabulationSO(word1, word2);
        return ans;

    }
};