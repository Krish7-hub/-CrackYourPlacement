class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int prefix = 1, suffix = 1;
        for(int i = 0; i < nums.size(); i++){
            prefix *= nums[i];
            suffix *= nums[n-i-1];
            ans = max(ans, max(prefix, suffix));
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
        }
        return ans;
    }
};