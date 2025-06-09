class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int>mpp;
        int n = nums.size();
        mpp[0] = 1;
        int count = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            int val = sum - k;
            count += mpp[val];
            mpp[sum]++;
        }
        return count;
    }
};