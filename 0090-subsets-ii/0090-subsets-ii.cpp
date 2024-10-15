class Solution {
public: 
    
    void solve(int index, vector<vector<int>>&ans, vector<int>&output, vector<int>&nums){
        ans.push_back(output);
        for(int i = index; i < nums.size(); i++){
            if(i != index && nums[i] == nums[i-1]) continue;
            output.push_back(nums[i]);
            solve(i+1, ans, output, nums);
            output.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>>ans;
        vector<int>output;
        int index = 0;
        sort(nums.begin(), nums.end());
        solve(index, ans, output, nums);
        return ans;

    }
};