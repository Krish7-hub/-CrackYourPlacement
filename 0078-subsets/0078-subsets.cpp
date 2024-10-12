class Solution {
public:
   void find(vector<int>&nums, int i, vector<int>&arr, int size, vector<vector<int>>&ans){
      if(i >= size){
        ans.push_back(arr);
        return;
      }
      arr.push_back(nums[i]);
      find(nums, i+1, arr, size, ans);
      arr.pop_back();
      find(nums, i+1, arr, size, ans);
   }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>arr;
        find(nums, 0, arr, nums.size(), ans);
        return ans;
    }
};