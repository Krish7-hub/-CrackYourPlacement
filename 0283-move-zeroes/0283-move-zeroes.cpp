class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i;
        for(int k = 0; k < nums.size(); k++){
            if(nums[k] == 0){
                i = k;
                break;
            }
        }
        for(int k = i + 1; k < nums.size(); k++){
            if(nums[k] != 0){
                swap(nums[i], nums[k]);
                i++;
            }
        }
    }
};