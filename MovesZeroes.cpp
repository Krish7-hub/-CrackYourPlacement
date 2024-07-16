class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int i , j = 0;
        for(int k = 0; k < nums.size(); k++){
            if(nums[k] == 0){
                i = k;
                break;
            }
        }
        j = i + 1;
        for(int k = j; k < nums.size(); k++){
            if(nums[k] != 0){
                swap(nums[i], nums[k]);
                i++;
            }
        }
    }
};
