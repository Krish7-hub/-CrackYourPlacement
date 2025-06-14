class Solution {
public:
    int findMinDivisor(int div, vector<int> &nums){
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += ceil(nums[i]/(double)div);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {

        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low <= high){
            int mid = low + (high - low)/2;
            int divisor = findMinDivisor(mid, nums);
            if(divisor <= threshold){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
        
    }
};