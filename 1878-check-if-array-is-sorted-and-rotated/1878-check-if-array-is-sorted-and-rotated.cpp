class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int len = nums.size();
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > nums[(i+1) % len]){
                count++;
            }
        }
        if(count <= 1){
            return true;
        }
        else{
            return false;
        }
    }
};