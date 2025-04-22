class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>>&dp){
        // base case
        if(i >= n || j < 0 || j >= n){
            return 100000;
        }
        if(i == (n-1)){
            return matrix[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int leftdiag = matrix[i][j] + solve(i+1, j-1, n, matrix, dp);
        int down = matrix[i][j] + solve(i+1, j, n, matrix, dp);
        int rightdiag = matrix[i][j] + solve(i+1, j+1, n, matrix, dp);
        dp[i][j] =  min(leftdiag, min(down, rightdiag));
        return dp[i][j];
    }

    int solveTabulation(vector<vector<int>>&matrix){ 

        int n = matrix.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            dp[n-1][i] = matrix[n-1][i];
        }

        for(int i = n-2; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                int leftdiag = 100000, down = 100000, rightdiag = 100000;
                if(j > 0) leftdiag = matrix[i][j] + dp[i+1][j-1];
                down = matrix[i][j] + dp[i+1][j];
                if(j < (n-1)) rightdiag = matrix[i][j] + dp[i+1][j+1];
                dp[i][j] =  min(leftdiag, min(down, rightdiag));
            }
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }


    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int n = matrix.size();
        // vector<vector<int>>dp(n, vector<int>(n, -1));
        // int ans = INT_MAX;
        // for(int j = 0; j < n; j++){
        //     int val = solve(0, j, n, matrix, dp);
        //     ans = min(ans, val);
        // }
        return solveTabulation(matrix);
    }
};