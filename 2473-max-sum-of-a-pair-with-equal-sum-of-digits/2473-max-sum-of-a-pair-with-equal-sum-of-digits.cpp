class Solution {
public:
    int getSumDigit(int val){
        int sum = 0;
        while(val > 0){
            sum += val % 10;
            val /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int>mpp;
        int maxSum = -1;
        for(int ele : nums){
            int sumDigit = getSumDigit(ele);
            if(mpp.count(sumDigit)){
                maxSum = max(maxSum, ele + mpp[sumDigit]);
                if(mpp[sumDigit] < ele){
                    mpp[sumDigit] = ele;
                }
            }
            else{
                mpp[sumDigit] = ele;
            }
        }
        return maxSum;
    }
};