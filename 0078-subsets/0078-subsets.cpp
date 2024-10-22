class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int sizeNum = nums.size();
        int subset = 1 << sizeNum;
        for(int i = 0; i < subset; i++){
            vector<int>temp;
            for(int j = 0; j < sizeNum; j++){
                if(i & (1 << j)){
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};