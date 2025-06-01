class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {

        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            if(nums[i] == nums[i+1]){
                nums[i] = nums[i] * 2;
                nums[i+1] = 0;
            }
        }

        int zeroIndex = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                zeroIndex = i;
                break;
            }
        }

        if(zeroIndex == -1){
            return nums;
        }

        for(int i = zeroIndex+1; i < n; i++){
            if(nums[i] != 0){
                swap(nums[i], nums[zeroIndex]);
                zeroIndex++;
            }
        }

        return nums;
        
    }
};