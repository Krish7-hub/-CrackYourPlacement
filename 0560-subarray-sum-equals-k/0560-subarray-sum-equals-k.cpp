class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        map<int, int>mpp;
        int preSum = 0;
        int count = 0;
        mpp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            preSum += nums[i];
            int find = preSum - k;
            count += mpp[find];
            mpp[preSum] += 1;
        }
        return count;
        
    }
};