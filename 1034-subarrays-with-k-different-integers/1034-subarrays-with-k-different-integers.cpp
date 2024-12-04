class Solution {
public:
    int find(vector<int>&nums, int k){
        int l = 0, r = 0, cnt = 0;
        map<int, int>mpp;
        while(r < nums.size()){
            mpp[nums[r]]++;
            while(mpp.size() > k && l <= r){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0){
                    mpp.erase(nums[l]);
                }
                l = l + 1;
            }
            cnt = cnt + (r - l + 1);
            r = r + 1;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        int part1 = find(nums, k);
        int part2 = find(nums, k-1);
        return part1 - part2;
        
    }
};