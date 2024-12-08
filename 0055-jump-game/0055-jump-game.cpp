class Solution {
public:
    bool canJump(vector<int>& nums) {

        int len = nums.size() - 1;
        int maxInd = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > maxInd) return false;
            if(maxInd >= len) return true;
            maxInd = max(maxInd, i + nums[i]);
        }
        return true;
        
    }
};