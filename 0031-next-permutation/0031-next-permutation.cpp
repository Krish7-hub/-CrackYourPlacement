class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int ind = -1;
        for(int i = len - 2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }
        if(ind == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i = len - 1; i > ind; i--){
            if(nums[i] > nums[ind]){
                swap(nums[i], nums[ind]);
                break;
            }
        }
        reverse(nums.begin() + ind + 1, nums.end());
        return;
    }
};