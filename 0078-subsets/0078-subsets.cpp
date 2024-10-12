class Solution {
public:
   void find(vector<int>&nums, int index, vector<int>output, vector<vector<int>>&ans){
      if(index >= nums.size()){
        ans.push_back(output);
        return;
      }
      find(nums, index+1, output, ans);
      output.push_back(nums[index]);
      find(nums, index+1, output, ans);
   }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        int index = 0;
        find(nums, index, output, ans);
        return ans;
    }
};