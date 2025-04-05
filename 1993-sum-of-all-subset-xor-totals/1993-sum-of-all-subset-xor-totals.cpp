class Solution {
public:
    int solve(int ind, vector<int>&nums, int val){
        if(ind == nums.size()){
            return val;
        }
        int inc = solve(ind + 1, nums, val ^ nums[ind]);
        int exc = solve(ind+1, nums, val);
        val = inc + exc;
        return val;
    }
    int subsetXORSum(vector<int>& nums) {
       int ind = 0;
       int val = 0;
       int ans = solve(ind, nums, val);
       return ans;

    }
};