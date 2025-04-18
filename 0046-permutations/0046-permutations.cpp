class Solution {
public: 
    
    void solve(int index, vector<int>&nums, vector<vector<int>>&ans){
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = index; i < nums.size(); i++){
            swap(nums[i], nums[index]);
            solve(index+1, nums, ans);
            swap(nums[i], nums[index]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>>ans;
        int index = 0;
        solve(index, nums, ans);
        return ans;
        
    }
};