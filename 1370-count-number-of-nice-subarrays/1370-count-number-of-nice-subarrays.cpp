class Solution {
public:
    
    int find(vector<int>&nums, int k){
        int left = 0, right = 0, sum = 0, cnt = 0;
        while(right < nums.size()){
            sum += (nums[right] % 2 == 0) ? 0 : 1;
            while(sum > k){
                sum -=  (nums[left] % 2 == 0) ? 0 : 1;
                left = left + 1;
            }
            cnt += (right - left + 1);
            right = right + 1;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int val = find(nums, k);
        int val2 = find(nums, k-1);
        int ans = val - val2;
        return ans;    
    }
};