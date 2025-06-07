class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

       vector<int>ans;
       unordered_map<int, int>mpp;
       int n = nums.size();
       int min = n/3 + 1;
       for(int i = 0; i < n; i++){
           mpp[nums[i]]++;
           if(mpp[nums[i]] == min){
            ans.push_back(nums[i]);
           }
       }
       return ans;
    }
};