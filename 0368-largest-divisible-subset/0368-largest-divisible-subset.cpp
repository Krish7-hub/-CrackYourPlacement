class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();

        int lis = 1;
        sort(nums.begin(), nums.end());
        vector<int>dp(n+1, 1);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                    if(lis < dp[i]){
                        lis = dp[i];
                    }
                }
            }
        }
        int prev = -1;
        for(int i = n-1; i >= 0; i--){
            if(dp[i] == lis && (prev == -1 || prev % nums[i] == 0)){
                ans.push_back(nums[i]);
                lis = lis - 1;
                prev = nums[i];
            }
        }
        return ans;
    }
};