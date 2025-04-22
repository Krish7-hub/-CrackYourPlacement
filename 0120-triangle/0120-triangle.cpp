class Solution {
public:
    int solveRecursion(int i, int j, int m, int n, vector<vector<int>>& triangle){
        // Base Case
        if(i == m-1){
            return triangle[i][j];
        }
        int same = triangle[i][j] + solveRecursion(i+1, j, m, n, triangle);
        int another = triangle[i][j] + solveRecursion(i+1, j+1, m, n, triangle);
        return min(same, another);
    }
    int solveMem(int i, int j, int m, int n, vector<vector<int>>& triangle, vector<vector<int>>&dp){
        // Base Case
        if(i == m-1){
            return triangle[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int same = triangle[i][j] + solveMem(i+1, j, m, n, triangle, dp);
        int another = triangle[i][j] + solveMem(i+1, j+1, m, n, triangle, dp);
        dp[i][j] = min(same, another);
        return dp[i][j];
    }
    int solveTab(vector<vector<int>>& triangle){

        int m = triangle.size();
        int n = triangle[m-1].size();

        vector<vector<int>>dp(m, vector<int>(n, -1));
        for(int i = 0; i < n; i++){
            dp[m-1][i] = triangle[m-1][i];
        }

        for(int i = m-2; i >= 0; i--){
            for(int j = 0; j < triangle[i].size(); j++){
                int same = triangle[i][j] + dp[i+1][j];
                int another = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(same, another);
            }
        }
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        // int ans = solveRecursion(0, 0, m, n, triangle);
        // int ans = solveMem(0, 0, m, n, triangle, dp);
        int ans = solveTab(triangle);
        return ans;
    }
};