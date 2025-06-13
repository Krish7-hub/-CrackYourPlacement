class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(i == 0 && nums[i] != nums[i+1]){
                return nums[i];
            }
            else if(i == nums.size()-1 && nums[i] != nums[i-1]){
                return nums[i];
            }
            else if(i > 1 && i < nums.size()-1 && nums[i] != nums[i-1] && nums[i] != nums[i+1]){
                return nums[i];
            }
        }
        return nums[0];
    }
};