class Solution {
public:
    // long long solve(int ind, vector<vector<int>>&questions){
    //     // Base Case
    //     if(ind >= questions.size()){
    //         return 0;
    //     }
    //     long long include = questions[ind][0] + solve(ind + questions[ind][1] + 1, questions);
    //     long long exclude = solve(ind + 1, questions);
    //     return max(include, exclude); 
    // }
    // long long solveUsingMem(long long ind, vector<long long>& dp, vector<vector<int>>& questions){
    //     // Base Case
    //     if(ind >= questions.size()){
    //         return 0;
    //     }
    //     if(dp[ind] != -1){
    //         return dp[ind];
    //     }
    //     long long include = questions[ind][0] + solveUsingMem(ind + questions[ind][1] + 1, dp, questions);
    //     long long exclude = solveUsingMem(ind + 1, dp, questions);
    //     dp[ind] = max(include, exclude);
    //     return dp[ind]; 
    // }
    long long solveUsingTabulation(vector<vector<int>>& questions){
        int n = questions.size();
        vector<long long>dp(n+1, 0);
        for(int ind = n-1; ind >= 0; ind--){
            int point = questions[ind][0];
            int jump = questions[ind][1];
            int nextQuestion = min(n, jump + ind + 1);
            dp[ind] = max(dp[ind+1], point + dp[nextQuestion]);
        }
        return dp[0];
    }
    long long mostPoints(vector<vector<int>>& questions) {
        long long ind = 0;
        long long  n = questions.size();
        // long long ans = solve(ind, questions);
        // vector<long long>dp(n+1, -1);
        long long ans = solveUsingTabulation(questions);
        return ans;
    }
};