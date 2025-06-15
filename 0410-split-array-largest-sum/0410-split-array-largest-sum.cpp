class Solution {
public:
    bool findSum(int val, vector<int>&nums, int k){
        int sum = nums[0];
        int count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(sum + nums[i] > val){
                count++;
                sum = nums[i];
                if(count > k) return false;
            }
            else{
                sum += nums[i];
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {

        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high){
            int mid = low + (high - low)/2;
            bool isSum = findSum(mid, nums, k);
            if(isSum){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;

    }
};