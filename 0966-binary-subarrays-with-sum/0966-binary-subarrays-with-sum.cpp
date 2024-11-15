class Solution {
public:
    int find(vector<int>&nums, int goal){
        if(goal < 0) return 0;
        int left = 0, right = 0, sum = 0, cnt = 0;
        while(right < nums.size()){
            sum = sum + nums[right];
            while(sum > goal){
                sum = sum - nums[left];
                left = left + 1;
            }
            cnt = cnt + (right - left + 1);
            right = right + 1;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int val = find(nums, goal);
        int val2 = find(nums, goal - 1);
        int ans = val - val2;
        return ans;
        
    }
};