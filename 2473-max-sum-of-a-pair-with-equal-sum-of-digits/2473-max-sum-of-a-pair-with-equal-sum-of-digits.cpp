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
        vector<int>maxArr(82, 0);
        int maxSum = -1;
        for(auto it : nums){
            int sumDigit = getSumDigit(it);
            if(maxArr[sumDigit] != 0){
                maxSum = max(maxSum, it + maxArr[sumDigit]);
                if(maxArr[sumDigit] < it){
                    maxArr[sumDigit] = it;
                }
            }
            else{
                maxArr[sumDigit] = it;
            }
        }
        return maxSum;
    }
};