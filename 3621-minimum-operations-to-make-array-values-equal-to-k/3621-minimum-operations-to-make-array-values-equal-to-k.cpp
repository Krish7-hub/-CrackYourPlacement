class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int opr = 0;
        int n = nums.size();
        int smallest = nums[n-1];
        for(int i = n-1; i >= 0; i--){
            if(nums[i] < smallest){
                opr++;
                smallest = nums[i];
            }
        }
        if(k == smallest){
            return opr;
        }
        else if(k < smallest){
            return 1+opr;
        }
        else{
            return -1;
        }
    }
};