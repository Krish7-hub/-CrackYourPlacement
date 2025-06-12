class Solution {
public:
    int lowerBound(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        int index = nums.size();
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] >= target){
                index = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return index;
    }
    int upperBound(vector<int>&nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        int index = nums.size();
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] > target){
                index = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return index;
    }
    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();
        int lb = lowerBound(nums, target);
        if(lb == n || nums[lb] != target) return {-1, -1};
        int ub = upperBound(nums, target);
        return {lb, ub-1};
        
    }
};