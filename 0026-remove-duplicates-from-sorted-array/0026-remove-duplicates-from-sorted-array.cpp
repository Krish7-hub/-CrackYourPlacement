class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int i = 0; 
        int j = 1;
        int count = 1;
        while(j < nums.size()){
            if(nums[j] == nums[i]){
                j++;
            }
            else{
                nums[i+1] = nums[j];
                i++;
                j++;
                count++;
            }
        }
        return count;
    }
};