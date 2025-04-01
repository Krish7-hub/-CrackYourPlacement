class Solution {
public:
   void printDP(vector<vector<int>>&dp){
    cout << "Printing DP Array " << endl;
      for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < dp[0].size(); j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
      }
   }
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
        // Step -> 3 If value is already exist then return that value.
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
        // Step -> 2 Store that computed value in dp.
        dp[i][j] = ans;
        printDP(dp);
        return dp[i][j];
    }

    int solveUsingTabulation(string& text1, string& text2, int n, int m){
        // Step 1 -> Create DP array.
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i = text1.size()-1; i >= 0; i--){
            for(int j = text2.size()-1; j >= 0; j--){
                int ans = 0;
                if(text1[i] == text2[j]){
                    ans = 1 + dp[i+1][j+1];
                }
                else{
                    ans = max(dp[i][j+1], dp[i+1][j]);
                }
                // Step -> 2 Store that computed value in dp.
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int solveUsingTabulationSO(string& text1, string& text2){
        // vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        vector<int>curr(text1.size()+1, 0);
        vector<int>next(text1.size()+1, 0);
         for(int j = text2.size()-1; j >= 0; j--){
            for(int i = text1.size()-1; i >= 0; i--){
                int ans = 0;
                if(text1[i] == text2[j]){
                    ans = 1 + next[i+1];
                }
                else{
                    ans = max(next[i], curr[i+1]);
                }
                // Step -> 2 Store that computed value in dp.
                curr[i] = ans;
            }
            // Shifting
            next = curr;
        }
        return curr[0];
    }

     int solveUsingTabulationNoLoopChange(string& text1, string& text2){
        vector<int>currRow(text2.length()+1, 0);
        vector<int>nextRow(text2.length()+1, 0);
       
        for(int i = text1.size()-1; i >= 0; i--){
            for(int j = text2.size()-1; j >= 0; j--){
                int ans = 0;
                if(text1[i] == text2[j]){
                    ans = 1 + nextRow[j+1];
                }
                else{
                    ans = max(currRow[j+1], nextRow[j]);
                }
                // Step -> 2 Store that computed value in dp.
                currRow[j] = ans;
            }
            // Shifting
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        // int ans = solveUsingRecursion(text1, text2, n, m);
        // Create DP Array.
        int i = 0; 
        int j = 0;
        // vector<vector<int>>dp(text1.size(), vector<int>(text2.size(), -1));
        // int ans = solveUsingMemoization(text1, text2, i, j, dp);
        // int ans = solveUsingTabulation(text1, text2, n, m);
        // int ans = solveUsingTabulationSO(text1, text2);
        int ans = solveUsingTabulationNoLoopChange(text1, text2);
        return ans;
    }
};